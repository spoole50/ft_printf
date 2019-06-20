/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_assist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:33:54 by spoole            #+#    #+#             */
/*   Updated: 2019/06/17 22:33:56 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print_zero(t_printf *info)
{
	char	*temp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	info->tot_writes++;
	temp = (char*)ft_memalloc(ft_strlen(info->result) + 2);
	while (info->result && info->result[i] != '\0')
		temp[x++] = info->result[i++];
	free(info->result);
	info->result = temp;
}

void			add_plus(t_mod *mod)
{
	char	*temp;
	int		size;
	int		i;
	int		x;

	i = 0;
	x = 0;
	size = ft_strlen(mod->arg_text);
	size++;
	temp = (char*)ft_memalloc(size + 1);
	temp[i++] = '+';
	while (mod->arg_text[x] != '\0')
		temp[i++] = mod->arg_text[x++];
	free(mod->arg_text);
	mod->arg_text = temp;
}

void			finish_signed(t_printf *info, t_mod *mod)
{
	signed_prec(mod);
	set_string(mod);
	add_string(info, mod->res);
}
