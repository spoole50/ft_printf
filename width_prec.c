/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:58:51 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:56:43 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		set_string(t_mod *mod)
{
	int		max;
	int		arg_len;

	arg_len = ft_strlen(mod->arg_text);
	max = (mod->sign != '0' && is_signed(mod->frmt_spec)\
	&& mod->arg_text[0] != '\0') ? 1 : 0;
	max = ((arg_len + max) < mod->min_wid) ? mod->min_wid : arg_len + max;
	mod->res = ft_memalloc(max + 1);
	if (mod->flags != NULL)
		add_flags(mod, max, arg_len);
	if (mod->res[0] == '\0')
	{
		while (mod->res_i < (max - arg_len))
			mod->res[mod->res_i++] = ' ';
		arg_to_string(mod);
	}
	else
	{
		while (mod->res_i < max)
			mod->res[mod->res_i++] = *mod->arg_text++;
	}
	if (mod->sign != '0' && is_signed(mod->frmt_spec))
		add_sign(mod);
}

void		string_precision(t_mod *mod)
{
	int		i;
	char	*new;

	i = 0;
	new = (char*)ft_memalloc(mod->precision + 1);
	while (i < mod->precision)
	{
		new[i] = mod->arg_text[i];
		i++;
	}
	mod->arg_text = new;
}

int			calc_prec(t_mod *mod, int *size)
{
	int		ret;
	int		sign;

	ret = 0;
	sign = has_sign(mod->arg_text);
	if (mod->flags != NULL)
	{
		if (mod->flags->plus == '1' && !(sign))
			mod->sign = '+';
		else if (mod->flags->space == '1' && is_signed(mod->frmt_spec))
			mod->sign = ' ';
	}
	if (mod->precision > *size)
		ret += (mod->precision - *size);
	if (sign)
	{
		mod->sign = '-';
		ret--;
		*size -= 1;
	}
	return (ret);
}

void		signed_prec_work(t_mod *mod, char *temp, int size)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while ((i < mod->precision || i <= size) && mod->arg_text[x] != '\0')
	{
		if (i < (mod->precision - size))
			temp[i++] = '0';
		else if (mod->arg_text[x] == '-')
		{
			x++;
			if (i < ((mod->precision - size) + 1) && temp[i - 1] != '0')
				temp[i++] = '0';
		}
		else
			temp[i++] = mod->arg_text[x++];
	}
}

void		signed_prec(t_mod *mod)
{
	char	*temp;
	int		size;

	temp = NULL;
	size = ft_strlen(mod->arg_text);
	check_zeros(mod);
	if (mod->precision > size || mod->flags)
	{
		temp = (char*)ft_memalloc(sizeof(char) *\
		(size + calc_prec(mod, &size) + 1));
		signed_prec_work(mod, temp, size);
		if (temp != NULL)
		{
			free(mod->arg_text);
			mod->arg_text = temp;
		}
	}
}
