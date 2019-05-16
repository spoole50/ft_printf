/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:50:12 by spoole            #+#    #+#             */
/*   Updated: 2019/05/08 14:50:26 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int         handle_mult_arg(t_printf *info, va_list ap)
{
    int i;

    i = read_number(info);
    if (i > info->max_args)
        info->max_args = i;
    while (info->cur_args < info->max_args)
        add_next_arg(info, ap);
    while (INPUT[INDEX] != '$')
        INDEX++;
    INDEX++;
    return (i);
}

int         add_next_arg(t_printf *info, va_list ap)
{
    arg_node_init(info, (void*)va_arg(ap, void*));
    return (++info->cur_args);
}

void        arg_node_init(t_printf *info, void *indata)
{
    t_arg_node  *temp;
    t_arg_node  *iter;

    if ((temp = (t_arg_node*)malloc(sizeof(t_arg_node))) == NULL)
        catch_error("t_arg_node initialization error", info);
    temp->index = info->cur_args + 1;
    temp->data = indata;
    temp->next = NULL;
    if (info->arg_begin == NULL)
        info->arg_begin = temp;
    else
    {
        iter = info->arg_begin;
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = temp;
    }
}