/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:56:32 by spoole            #+#    #+#             */
/*   Updated: 2019/05/01 16:56:33 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_mod           *t_mod_init(t_printf *info)
{
    t_mod *temp;

    if ((temp = (t_mod*)malloc(sizeof(t_mod))) == NULL)
        catch_error("t_mod init error", info);
    temp->min_wid = 0;
    temp->cur_size = 0;
    temp->frmt_spec = ' ';
    return (temp);
}

t_printf        *t_printf_init(char *in)
{
    t_printf    *temp;

    if ((temp = (t_printf*)malloc(sizeof(t_printf))) == NULL)
        catch_error("t_printf initialization error", NULL);
    temp->len = 0;
    temp->in = 0;
    temp->input = in;
    temp->cur_args = 0;
    temp->max_args = 0;
    temp->str_begin = NULL;
    temp->arg_begin = NULL;
    return (temp);
}