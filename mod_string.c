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