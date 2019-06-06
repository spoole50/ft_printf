/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:50:12 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:13:50 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_arg_node		*find_arg(t_arg_node *begin, int arg_num)
{
	while (begin->index != arg_num)
		begin = begin->next;
	return (begin);
}

int				handle_mult_arg(t_printf *info, va_list ap, char fs)
{
	int			i;

	i = read_number(info);
	if (i > info->max_args)
		info->max_args = i;
	while (info->cur_args < info->max_args)
		add_next_arg(info, ap, fs);
	while (INPUT[INDEX] != '$')
		INDEX++;
	INDEX++;
	return (i);
}

int				add_next_arg(t_printf *info, va_list ap, char fs)
{
	t_arg_node	*temp;

	temp = arg_node_init(info);
	if (is_float(fs))
		temp->data.flt = (double)va_arg(ap, double);
	else
		temp->data.vdata = (void*)va_arg(ap, void*);
	return (++info->cur_args);
}

t_arg_node			*arg_node_init(t_printf *info)
{
	t_arg_node	*temp;
	t_arg_node	*iter;

	if ((temp = (t_arg_node*)malloc(sizeof(t_arg_node))) == NULL)
		catch_error("t_arg_node initialization error", info);
	temp->index = info->cur_args + 1;
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
	return (temp);
}
