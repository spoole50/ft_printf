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
    t_arg_node  *arg;

    temp = NULL;
    arg = info->arg_begin;
    while (arg->index != mod->arg_num)
        arg = arg->next;
    if (mod->frmt_spec == 'c')
        mod->arg_text = (char*)&arg->data;
    else if (arg->data == NULL)
        mod->arg_text = "(null)";
    else
        mod->arg_text = (char*)arg->data;
    if (mod->precision != -1 && mod->frmt_spec != 'c')
        string_precision(mod);
    set_string(mod);
    add_string(info, mod->res);
}

t_arg_node      *find_arg(t_arg_node *begin, int arg_num)
{
    while (begin->index != arg_num)
        begin = begin->next;
    return (begin);
}

int     has_sign(char *s1)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '-')
            return (1);
        i++;
    }
    return (0);
}

void    signed_prec(t_mod *mod)
{
    char    *temp;
    int     size;
    int     i;
    int     x;

    i = 0;
    x = 0;
    size = ft_strlen(mod->arg_text);
    if (mod->arg_text[0] == '0' && mod->precision == 0)
        mod->arg_text[0] = '\0';
    if (mod->precision > size || mod->flags)
    {
        mod->precision += ((mod->flags && (mod->flags->plus == '1' || (mod->flags->space == '1' && is_signed(mod->frmt_spec)))) || (has_sign(mod->arg_text))) ? 1 : 0;
        temp = (char*)ft_memalloc(sizeof(char) * (mod->precision + 1));
        if (has_sign(mod->arg_text))
        {
            temp[i++] = '-';
            size--;
        }
        else if (mod->flags && mod->flags->plus == '1')
            temp[i++] = '+';
        else if (mod->flags && mod->flags->space == '1' && is_signed(mod->frmt_spec))
            temp[i++] = ' ';
        while (i < mod->precision || mod->arg_text[x] != '\0')
        {
            if (i < (mod->precision  - size))
                temp[i++] = '0';
            else if (mod->arg_text[x] == '-')
                x++;
            else
                temp[i++] = mod->arg_text[x++];
        }
        free(mod->res);
        mod->arg_text = temp;
    }
}

void    mod_string_signed(t_printf *info, t_mod *mod)
{
    t_arg_node *arg;

    arg = find_arg(info->arg_begin, mod->arg_num);
    if (mod->len_mod[0] == '0')
        mod->arg_text = ft_itoa((int)arg->data);
    if (mod->len_mod[0] == 'l')
    {
        if (mod->len_mod[1] == 'l')
            mod->arg_text = ft_itoa((long long)arg->data);
        else
            mod->arg_text = ft_itoa((long)arg->data);
    }
    else if (mod->len_mod[0] == 'h')
    {
        if (mod->len_mod[1] == 'h')
            mod->arg_text = ft_itoa((signed char)arg->data);
        else
            mod->arg_text = ft_itoa((short)arg->data);
    }
    signed_prec(mod);
    set_string(mod);
    (mod->res != NULL) ? add_string(info, mod->res) : catch_error("mod_string_signed error", info);
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

void    add_x(t_mod *mod)
{
    int     size;
    char    *tmp;
    int     i;
    int     x;

    i = 0;
    x = 0;
    size = ft_strlen(mod->arg_text) + 3;
    tmp = (char*)ft_memalloc(sizeof(char) * size);
    tmp[i++] = '0';
    tmp[i++] = (mod->frmt_spec == 'x') ? 'x' : 'X';
    while (i < size)
        tmp[i++] = mod->arg_text[x++];
    free(mod->arg_text);
    mod->arg_text = tmp;
}

void    mod_string_unsigned(t_printf *info, t_mod *mod)
{
    t_arg_node *arg;

    arg = find_arg(info->arg_begin, mod->arg_num);
    if (mod->frmt_spec == 'o')
        mod->arg_text = unsigned_len_mod(arg, mod, 8);
    else if (mod->frmt_spec == 'u')
        mod->arg_text = unsigned_len_mod(arg, mod, 10);
    else if (mod->frmt_spec == 'x' || mod->frmt_spec == 'X')
        mod->arg_text = unsigned_len_mod(arg, mod, 16);
    if (mod->frmt_spec == 'x')
        lower(mod->arg_text);
    if (mod->frmt_spec == 'o' && mod->flags && mod->flags->hash == '1' && mod->arg_text[0] != '0')
        mod->precision = 1;
    signed_prec(mod);
    if (mod->flags && mod->flags->hash == '1' && (mod->frmt_spec == 'x' || mod->frmt_spec == 'X') && mod->arg_text[0] != '0')
        add_x(mod);
    set_string(mod);
    add_string(info, mod->res);
}

void    mod_string_float(t_printf *info, t_mod *mod)
{
    t_arg_node *arg;
    char *temp;
    long double *p;

    temp = NULL;
    arg = find_arg(info->arg_begin, mod->arg_num);
    p = (long double*)arg->data;
    temp = ft_ftoa(*p, mod->precision);
    add_string(info, temp);
    free(temp);
}