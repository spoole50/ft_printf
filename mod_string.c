/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:03:25 by spoole            #+#    #+#             */
/*   Updated: 2019/05/15 19:03:26 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void    string_precision(t_mod *mod)
{
    int     i;
    char    *new;
    
    i = 0;
    new = (char*)ft_memalloc(mod->precision + 1);
    while (i < mod->precision)
    {
        new[i] = mod->arg_text[i];
        i++;
    }
    mod->arg_text = new;
}

void    mod_string_char(t_printf *info, t_mod *mod)
{
    char        *temp;
    char        c;
    t_arg_node  *arg;

    c = ' ';
    temp = NULL;
    arg = info->arg_begin;
    while (arg->index != mod->arg_num)
        arg = arg->next;
    if (mod->frmt_spec == 'c')
    {
        c = (char)arg->data;
        mod->arg_text = &c;
    }
    else if (arg->data == NULL)
        mod->arg_text = "(null)";
    else
        mod->arg_text = (char*)arg->data;
    if (mod->precision != -1 && mod->frmt_spec != 'c')
        string_precision(mod);
    set_string(mod);
    add_string(info, mod->res);
}

void    mod_string_signed(t_printf *info, t_mod *mod)
{
    t_arg_node *arg;
    char *temp;

    arg = info->arg_begin;
    temp = NULL;
    while (arg->index != mod->arg_num)
        arg = arg->next;
    if (mod->len_mod[0] == '0')
        temp = ft_itoa((int)arg->data);
    if (mod->len_mod[0] == 'l')
    {
        if (mod->len_mod[1] == 'l')
            temp = ft_itoa((long long)arg->data);
        else
            temp = ft_itoa((long)arg->data);
    }
    else if (mod->len_mod[0] == 'h')
    {
        if (mod->len_mod[1] == 'h')
            temp = ft_itoa((signed char)arg->data);
        else
            temp = ft_itoa((short)arg->data);
    }
    (temp != NULL) ? add_string(info, temp) : catch_error("mod_string_signed error", info);
}

char    *unsigned_len_mod(t_arg_node *arg, t_mod *mod, int base)
{
    char *temp;

    temp = NULL;
    if (mod->len_mod[0] == 'l')
    {
        if (mod->len_mod[1] == 'l')
            temp = ft_itoab_unsigned((unsigned long long)arg->data, base);
        else
            temp = ft_itoab_unsigned((unsigned long)arg->data, base);
    }
    else if (mod->len_mod[0] == 'h')
    {
        if (mod->len_mod[1] == 'h')
            temp = ft_itoab_unsigned((unsigned char)arg->data, base);
        else
            temp = ft_itoab_unsigned((unsigned short)arg->data, base);
    }
    else
        temp = ft_itoab_unsigned((unsigned int)arg->data, base);
    return (temp);
}

void    lower(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ft_tolower(str[i]);
        i++;
    }
}

void    mod_string_unsigned(t_printf *info, t_mod *mod)
{
    t_arg_node *arg;
    char *temp;

    temp = NULL;
    arg = info->arg_begin;
    while (arg->index != mod->arg_num)
        arg = arg->next;
    if (mod->frmt_spec == 'o')
        temp = unsigned_len_mod(arg, mod, 8);
    else if (mod->frmt_spec == 'u')
        temp = unsigned_len_mod(arg, mod, 10);
    else if (mod->frmt_spec == 'x' || mod->frmt_spec == 'X')
        temp = unsigned_len_mod(arg, mod, 16);
    if (mod->frmt_spec == 'x')
        lower(temp);
    add_string(info, temp);
} 