/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:16:31 by spoole            #+#    #+#             */
/*   Updated: 2019/05/08 12:16:34 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char            *build_str(t_printf *info)
{
    char        *result;
    t_str_node  *temp;

    result = NULL;
    temp = info->str_begin;
    while (temp != NULL)
    {
        result = ft_strjoin(result, temp->str);
        temp = temp->next;
    }
    return (result);
}

void        fill_node(t_printf *info, int len)
{
    t_str_node *temp;
    
    temp = info->str_begin;
    while (temp->next != NULL)
        temp = temp->next;
    if ((temp->str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
        catch_error("str_node string malloc failure", info);
    len += info->in;
    while (info->in < len)
        temp->str[temp->i++] = info->input[info->in++];
    temp->str[temp->i] = '\0';
}

void        str_node_init(t_printf *info, int len)
{
    t_str_node  *temp;
    t_str_node  *iter;

    if ((temp = (t_str_node*)malloc(sizeof(t_str_node))) == NULL)
        catch_error("t_arg_node initialization error", info);
    temp->i = 0;
    temp->str = NULL;
    temp->next = NULL;
    if (info->str_begin == NULL)
        info->str_begin = temp;
    else
    {
        iter = info->str_begin;
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = temp;
    }
}
