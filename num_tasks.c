/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_tasks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:05:20 by spoole            #+#    #+#             */
/*   Updated: 2019/06/19 23:33:23 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			is_zeros(char *s1)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!is_empty(s1[i]))
			return (0);
		i++;
	}
	return (1);
}

int			calc_x_pad(t_mod *mod, int size)
{
	int		sp;
	int		i;

	sp = 0;
	i = -1;
	while (mod->res[++i] != '\0')
	{
		if (is_space(mod->res[i]))
			sp++;
		if (mod->frmt_spec == 'p' && mod->flags && mod->flags->zero == '1' && mod->res[i] == '0')
			sp++;
	}
	i = size;
	i -= sp;
	if (size == i)
		return (3);
	else if (sp > 2)
		return (1);
	else if (size >= mod->min_wid && i > 2)
		return ((size - i) + 1);
	else
		return (1);
}

int			calc_more_pad(t_mod *mod, int i)
{
	if (mod->min_wid != 0)
	{
		if (mod->frmt_spec == 'p' && is_space(mod->res[i]))
			return (2);
		else if (mod->frmt_spec != 'p' && is_empty(mod->res[i]))
			return (2);
	}
	return (0);
}

void		add_x(t_mod *mod)
{
	int		size;
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	tmp = NULL;
	if (is_zeros(mod->res) && mod->frmt_spec != 'p')
		return ;
	size = ft_strlen(mod->res);
	size += calc_x_pad(mod, size);
	tmp = (char*)ft_memalloc(sizeof(char) * size);
	if (mod->min_wid != 0 && !ft_isalnum(mod->res[0]))
		while (!ft_isalnum(mod->res[x + 2]))
			tmp[i++] = mod->res[x++];
	x += calc_more_pad(mod, i);
	tmp[i++] = '0';
	tmp[i++] = (mod->frmt_spec == 'X') ? 'X' : 'x';
	while (i < (size - 1))
		tmp[i++] = mod->res[x++];
	if (mod->res)
		free(mod->res);
	mod->res = tmp;
}

char		*unsigned_len_mod(t_arg_node *arg, t_mod *mod, int base)
{
	char	*temp;

	temp = NULL;
	if (mod->len_mod[0] == 'l')
	{
		if (mod->len_mod[1] == 'l')
			temp = ft_itoab_unsigned((unsigned long long)arg->data.vdata, base);
		else
			temp = ft_itoab_unsigned((unsigned long)arg->data.vdata, base);
	}
	else if (mod->len_mod[0] == 'h')
	{
		if (mod->len_mod[1] == 'h')
			temp = ft_itoab_unsigned((unsigned char)arg->data.vdata, base);
		else
			temp = ft_itoab_unsigned((unsigned short)arg->data.vdata, base);
	}
	else if (mod->len_mod[0] == 'j' || mod->len_mod[0] == 'z')
		temp = ft_itoab_unsigned((uintmax_t)arg->data.vdata, base);
	else
		temp = ft_itoab_unsigned((unsigned int)arg->data.vdata, base);
	return (temp);
}
