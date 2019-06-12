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

void		add_flags(t_mod *mod, int max, int arg_len)
{
	if (mod->flags->minus == '1')
	{
		arg_to_string(mod);
		while (mod->res_i < max)
			mod->res[mod->res_i++] = ' ';
		mod->res[mod->res_i] = '\0';
	}
	if (mod->flags->zero == '1' && mod->precision == -1)
	{
		while (mod->res_i < (max - arg_len))
			mod->res[mod->res_i++] = '0';
	}
}

void		add_sign(t_mod *mod)
{
	int i;

	i = 0;
	while (mod->res[i] != '\0' && !ft_isalnum(mod->res[i + 1]))
		i++;
	mod->res[i] = mod->sign;
}

void		set_string(t_mod *mod)
{
	int		max;
	int		arg_len;

	arg_len = ft_strlen(mod->arg_text);
	max = (mod->sign == '0') ? 0 : 1;
	max = ((arg_len + max) < mod->min_wid) ? mod->min_wid : arg_len;
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
	if (mod->sign != '0')
		add_sign(mod);
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

int				calc_prec(t_mod *mod, int size)
{
	int ret;

	ret = 0;
	if (mod->flags != NULL)
	{
		if (mod->flags->plus == '1' && !(has_sign(mod->arg_text)))
			mod->sign = '+';
		else if (has_sign(mod->arg_text))
		{
			mod->sign = '-';
			ret--;
		}
		else if (mod->flags->space == '1' && is_signed(mod->frmt_spec))
			mod->sign = ' ';
	}
	if (mod->precision > size)
		ret += (mod->precision - size);
	return (ret);
}

/*void		signed_prec(t_mod *mod)
{
	char	*temp;
	int		size;
	int		i;
	int		x;

	i = 0;
	x = 0;
	temp = NULL;
	size = ft_strlen(mod->arg_text);
	if (mod->arg_text[0] == '0' && mod->precision == 0)
		mod->arg_text[0] = '\0';
	if (mod->precision > size || mod->flags)
	{
		temp = (char*)ft_memalloc(sizeof(char) * (size + calc_prec(mod, size) + 1));
		if (has_sign(mod->arg_text))
			temp[i++] = '-';
		else if (mod->flags && mod->flags->plus == '1')
			temp[i++] = '+';
		else if (mod->flags && mod->flags->space == '1' && is_signed(mod->frmt_spec))
			temp[i++] = ' ';
		while ((i < mod->precision || i <= size) && mod->arg_text[x] != '\0')
		{
			if (i < (mod->precision - size))
				temp[i++] = '0';
			else if (mod->arg_text[x] == '-')
				x++;
			else
				temp[i++] = mod->arg_text[x++];
		}
		if (temp != NULL)
		{
			free(mod->arg_text);
			mod->arg_text = temp;
		}
	}
}*/

void		signed_prec(t_mod *mod)
{
	char	*temp;
	int		size;
	int		i;
	int		x;

	i = 0;
	x = 0;
	temp = NULL;
	size = ft_strlen(mod->arg_text);
	if (mod->arg_text[0] == '0' && mod->precision == 0)
		mod->arg_text[0] = '\0';
	if (mod->precision > size || mod->flags)
	{
		temp = (char*)ft_memalloc(sizeof(char) * (size + calc_prec(mod, size) + 1));
		while ((i < mod->precision || i <= size) && mod->arg_text[x] != '\0')
		{
			if (i < (mod->precision - size))
				temp[i++] = '0';
			else if (mod->arg_text[x] == '-')
				x++;
			else
				temp[i++] = mod->arg_text[x++];
		}
		if (temp != NULL)
		{
			free(mod->arg_text);
			mod->arg_text = temp;
		}
	}
}
