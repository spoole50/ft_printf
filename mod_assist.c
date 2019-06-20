/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_assist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:52:49 by spoole            #+#    #+#             */
/*   Updated: 2019/06/17 22:29:32 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			read_number(t_printf *info)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char*)ft_memalloc(10);
	while (ft_isnum(INPUT[INDEX]) || is_space(INPUT[INDEX]))
	{
		if (ft_isnum(INPUT[INDEX]))
			temp[i++] = INPUT[INDEX];
		INDEX++;
	}
	i = ft_atoi(temp);
	free(temp);
	return (i);
}

void		handle_flags(t_printf *info, t_mod *mod)
{
	t_flags	*temp;

	temp = t_flags_init(mod);
	while (is_flag(INPUT[INDEX]) || is_space(INPUT[INDEX]))
	{
		if (INPUT[INDEX] == '#')
			temp->hash = '1';
		if (INPUT[INDEX] == '-')
			temp->minus = '1';
		if (INPUT[INDEX] == '+')
			temp->plus = '1';
		if (INPUT[INDEX] == '0')
			temp->zero = '1';
		if (is_space(INPUT[INDEX]))
			temp->space = '1';
		INDEX++;
	}
	mod->flags = temp;
}

void		handle_precision(t_printf *info, t_mod *mod)
{
	INDEX++;
	while (is_space(INPUT[INDEX]))
		INDEX++;
	if (ft_isnum(INPUT[INDEX]))
		mod->precision = read_number(info);
	else
		mod->precision = 0;
}

char		*handle_num(t_printf *info)
{
	int		i;
	char	*res;

	res = NULL;
	i = info->in;
	return (res);
}

void		arg_to_string(t_mod *mod)
{
	int		i;

	i = 0;
	while (mod->arg_text[i] != '\0')
		mod->res[mod->res_i++] = mod->arg_text[i++];
	if (*(mod->arg_text) == '\0' && i == 0 && mod->frmt_spec == 'c')
		mod->res[mod->res_i++] = (char)0;
}
