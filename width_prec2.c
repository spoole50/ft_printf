/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:56:53 by spoole            #+#    #+#             */
/*   Updated: 2019/06/17 22:56:55 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			check_arg(char *str, int i)
{
	if (ft_isnum(str[i]) || is_space(str[i]))
	{
		while (ft_isnum(str[i]) || is_space(str[i]))
			i++;
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

void		check_zeros(t_mod *mod)
{
	int		i;

	i = 0;
	if (mod->arg_text[0] == 48 && mod->precision == 0)
	{
		if (mod->frmt_spec != 'o' || (!mod->flags))
			mod->arg_text[0] = '\0';
	}
	if (mod->frmt_spec == 'o' && mod->flags && mod->flags->hash == '1')
	{
		if (mod->arg_text[0] == '0')
			return ;
		i = 1 + ft_strlen(mod->arg_text);
		if (mod->min_wid == 0 || mod->flags->zero == '0' || i > mod->min_wid\
		|| mod->precision != -1)
			mod->precision = (i > mod->precision) ? i : mod->precision;
	}
}

int			count_empty(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (!is_space(*str))
			i++;
		str++;
	}
	return (i);
}

void		add_flags(t_mod *mod, int max, int *arg_len)
{
	if (mod->flags->minus == '1')
	{
		if (mod->flags->plus == '1')
		{
			mod->res[mod->res_i++] = mod->sign;
			mod->sign = '0';
		}
		arg_to_string(mod);
		while (mod->res_i < max)
		{
			mod->res[mod->res_i++] = ' ';
		}
		mod->res[mod->res_i] = '\0';
	}
	if (mod->flags->zero == '1' && mod->precision == -1)
	{
		while (mod->res_i < (max - *arg_len))
			mod->res[mod->res_i++] = '0';
	}
	if (mod->flags->plus == '1' && *arg_len == 0)
		*arg_len += 1;
}

void		add_sign(t_mod *mod)
{
	int		i;
	int		x;
	char	*temp;

	i = 0;
	x = 0;
	while (mod->res[i] != '\0' && !ft_isalnum(mod->res[i])\
	&& !ft_isalnum(mod->res[i + 1]))
		i++;
	if (mod->flags && mod->flags->minus == '1')
	{
		temp = ft_strdup(mod->res);
		temp[i++] = mod->sign;
		while (temp[i] != '\0')
			temp[i++] = mod->res[x++];
		free(mod->res);
		mod->res = temp;
	}
	else
		mod->res[i] = mod->sign;
}
