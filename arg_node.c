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

void        arg_node_init(t_printf *info, void *indata)
{
    t_arg_node  *temp;
    t_arg_node  *iter;

    if ((temp = (t_arg_node*)malloc(sizeof(t_arg_node))) == NULL)
        catch_error("t_arg_node initialization error", info);
    temp->index = info->cur_args + 1;
    temp->data = indata;
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