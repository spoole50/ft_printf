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
    char temp[10];
    int i;

    i = 0;
    while (ft_isnum(INPUT[INDEX]))
        temp[i++] = INPUT[INDEX++];
    i = ft_atoi((char*)&temp);
    return (i);
}

void    handle_percent(t_printf *info)
{
    str_node_init(info);
    fill_node(info, 1);
}

void    handle_flags(t_printf *info, t_mod *mod)
{
    t_flags *temp;
    temp = t_flags_init(info, mod);
    while (is_flag(INPUT[INDEX]))
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
    if (ft_isnum(INPUT[INDEX]))
        mod->precision = read_number(info);
    else
        mod->precision = 0;
    
}

char    *handle_string(t_printf *info, int arg_num)
{
    t_arg_node *temp;

    INDEX++;
    temp = info->arg_begin;
    while (temp->index != arg_num)
        temp = temp->next;
    return ((char*)temp->data);
}

char    *handle_len_mod(t_printf *info)
{
    int i;
    char *res;
    
    res = NULL;
    i = info->len;
    return (res);
}

char    *handle_num(t_printf *info)
{
    int i;
    char *res;
    
    res = NULL;
    i = info->len;
    return (res);
}

void    create_mod_string(t_printf *info, t_mod *mod)
{
    char *res_string;
    char *temp;
    int  res_len;
    int i;

    res_len = 0;
    i = 0;
    if (mod->frmt_spec == 's')
        temp = handle_string(info, mod->arg_num);
    else if (mod->len_mod == '1')
        temp = handle_len_mod(info);
    else
        temp = handle_num(info);
    res_len = ft_strlen(temp);
    if (res_len < mod->min_wid)
        i = mod->min_wid;
    else
        i = res_len;
    res_string = ft_memalloc(i + 1);
    i = -1;
    while (++i < res_len)
        res_string[i] = temp[i];
    res_string[i] = '\0';
    add_string(info, res_string);
}

void    handle_mod(t_printf *info, va_list ap)
{
    t_mod *temp;

    temp = t_mod_init(info);
    INDEX++;
    if ((temp->frmt_spec = is_invalid_conv_spec(INPUT, INDEX)) == 'E')
        catch_error("Invalid Conversion Specification", info);
    if (temp->frmt_spec == '%')
        handle_percent(info);
    else
    {
        if (check_arg(INPUT, INDEX))
            temp->arg_num = handle_mult_arg(info, ap);
        else
            temp->arg_num = add_next_arg(info, ap);
        if (is_flag(INPUT[INDEX]))
            handle_flags(info, temp);
        if (ft_isnum(INPUT[INDEX]))
            temp->min_wid = read_number(info);
        if (INPUT[INDEX] == '.')
            handle_precision(info, temp);
        if (is_len_mod(INPUT, INDEX))
            temp->len_mod = '1';
        create_mod_string(info, temp);
    }
    free(temp);
}