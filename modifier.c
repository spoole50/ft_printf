/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:21:30 by spoole            #+#    #+#             */
/*   Updated: 2019/05/01 21:21:31 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int    read_number(t_printf *info)
{
    char *temp;
    int i;

    i = 0;
    temp = (char*)ft_memalloc(10);
    while (ft_isnum(INPUT[INDEX]) || is_space(INPUT[INDEX]))
    {
        if (ft_isnum(INPUT[INDEX]))
            temp[i++] = INPUT[INDEX];
        INDEX++;
    }
    i = ft_atoi(temp);
    free(temp);
    return (i);
}

void    handle_flags(t_printf *info, t_mod *mod)
{
    t_flags *temp;
    temp = t_flags_init(info, mod);
    while (is_flag(INPUT[INDEX]) || is_space(INPUT[INDEX]))
    {
        if (INPUT[INDEX] == '#')
            temp->hash = '1';
        if (INPUT[INDEX] == '-')
            temp->minus = '1';
        if (INPUT[INDEX] == '+')
            temp->plus = '1';
        if (INPUT[INDEX] == '0')
            temp->zero = '1';
        INDEX++;
    }
    mod->flags = temp;
}

void    handle_precision(t_printf *info, t_mod *mod)
{
    INDEX++;
    while (is_space(INPUT[INDEX]))
        INDEX++;
    if (ft_isnum(INPUT[INDEX]))
        mod->precision = read_number(info);
    else
        mod->precision = 0;
}

char    *handle_num(t_printf *info)
{
    int i;
    char *res;
    
    res = NULL;
    i = info->in;
    return (res);
}

void    arg_to_string(t_mod* mod)
{
    int i;

    i = 0;
    while (mod->arg_text[i] != '\0')
            mod->res[mod->res_i++] = mod->arg_text[i++];
    if (*(mod->arg_text) == '\0' && i == 0 && mod->frmt_spec == 'c')
        mod->res[mod->res_i++] = (char)0;

}

void    set_string(t_mod *mod)
{
    int     max;
    int     arg_len;
    
    arg_len = ft_strlen(mod->arg_text);
    max = (arg_len < mod->min_wid) ? mod->min_wid : arg_len;
    mod->res = ft_memalloc(max + 1);
    if (mod->flags != NULL)
    {
        if (mod->flags->minus == '1')
        {
            arg_to_string(mod);
            while(mod->res_i < max)
                mod->res[mod->res_i++] = ' ';
            mod->res[mod->res_i] = '\0';
        }
        else if (mod->flags->zero == '1')
        {
            while (mod->res_i < (max - arg_len))
                mod->res[mod->res_i++] = '0';
        }
    }
    else
    {
        while (mod->res_i < (max - arg_len))
            mod->res[mod->res_i++] = ' ';
        arg_to_string(mod);
    }
    if (mod->precision != -1 && mod->frmt_spec != 'c')
        free(mod->arg_text);
}

int     count_empty(char *str)
{
    int i;

    i = 0;
    while (*str != '\0')
    {
        if (!is_space(*str))
            i++;
        str++;
    }
    return (i);
}

void    handle_len_mod(t_printf *info, t_mod *mod)
{
    int i;

    i = 0;
    while (!(is_conv(INPUT[INDEX])))
        mod->len_mod[i++] = INPUT[INDEX++];
}

void    validate_conv_spec(t_printf *info, t_mod *mod)
{
    int len;
    int i;

    i = 0;
    if ((len = is_invalid_conv_spec(INPUT, INDEX)) == -1)
        catch_error("Invalid Conversion Specification", info);
    mod->frmt_spec = INPUT[INDEX + len];
}

void    parse_spec(t_printf *info, t_mod *mod)
{
    while (INDEX[INPUT] != mod->frmt_spec)
    {
        if (is_flag(INPUT[INDEX]))
            handle_flags(info, mod);
        else if (ft_isnum(INPUT[INDEX]))
            mod->min_wid = read_number(info);
        else if(INPUT[INDEX] == '.')
            handle_precision(info, mod);
        else if (is_len_mod(INPUT, INDEX))
            handle_len_mod(info, mod);
        else
            INDEX++;
    }
    INDEX++;
}

void    handle_mod(t_printf *info, va_list ap)
{
    t_mod *mod;

    mod = t_mod_init(info);
    INDEX++;
    validate_conv_spec(info, mod);
    if (is_other(mod->frmt_spec))
        mod->arg_text = "%";
    else
    {
        if (check_arg(INPUT, INDEX))
            mod->arg_num = handle_mult_arg(info, ap);
        else
            mod->arg_num = add_next_arg(info, ap);
    }
    parse_spec(info, mod);
    if (is_text(mod->frmt_spec) || is_other(mod->frmt_spec))
        mod_string_char(info, mod);
    else if (is_signed(mod->frmt_spec))
        mod_string_signed(info, mod);
    else if (is_unsigned(mod->frmt_spec))
        mod_string_unsigned(info, mod);
    else if (is_float(mod->frmt_spec))
        mod_string_float(info, mod);
    free(mod);
}