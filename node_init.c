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

t_flags         *t_flags_init(t_printf *info, t_mod *mod)
{
    t_flags *temp;

    if ((temp = (t_flags*)malloc(sizeof(t_flags))) == NULL)
    {
        free(mod);
        catch_error("t_flags init error", info);
    }
    temp->hash = '0';
    temp->minus = '0';
    temp->plus = '0';
    temp->zero = '0';
    temp->space = '0';
    return (temp);
}

t_mod           *t_mod_init(t_printf *info)
{
    t_mod *temp;

    if ((temp = (t_mod*)malloc(sizeof(t_mod))) == NULL)
        catch_error("t_mod init error", info);
    temp->min_wid = 0;
    temp->arg_num = 0;
    temp->precision = -1;
    temp->cur_size = 0;
    temp->res_i = 0;
    temp->frmt_spec = ' ';
    temp->flags = NULL;
    temp->res = NULL;
    temp->arg_text = 0;
    temp->len_mod[0] = '0';
    temp->len_mod[1] = '0';
    return (temp);
}

void            clean_tprintf(t_printf *info)
{
    t_arg_node *clean_arg;
    t_arg_node *temp_arg;

    if (info == NULL)
        return;
    if (info->arg_begin != NULL)
    {
        clean_arg = info->arg_begin;
        while (clean_arg != NULL)
        {
            temp_arg = clean_arg->next;
            free(clean_arg);
            clean_arg = temp_arg;
        }
    }
    free(info);
}

t_printf        *t_printf_init(char *in)
{
    t_printf    *temp;

    if ((temp = (t_printf*)malloc(sizeof(t_printf))) == NULL)
        catch_error("t_printf initialization error", NULL);
    temp->tot_writes = 0;
    temp->in = 0;
    temp->input = in;
    temp->cur_args = 0;
    temp->max_args = 0;
    temp->result = NULL;
    temp->arg_begin = NULL;
    return (temp);
}