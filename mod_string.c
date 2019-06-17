/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:03:25 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:37:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			mod_string_char(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = NULL;
	if (mod->frmt_spec != '%')
		arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->frmt_spec == 'c' || mod->frmt_spec == 'C')
		mod->arg_text = (char*)&arg->data.vdata;
	else if (arg != NULL && arg->data.vdata == NULL)
		mod->arg_text = "(null)";
	else if (mod->frmt_spec != '%')
		mod->arg_text = (char*)arg->data.vdata;
	if (mod->precision != -1 && mod->frmt_spec != 'c')
		string_precision(mod);
	set_string(mod);
	add_string(info, mod->res);
}

void			mod_string_signed(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->len_mod[0] == '0')
		mod->arg_text = ft_itoa((int)arg->data.vdata);
	else if (mod->len_mod[0] == 'l')
	{
		if (mod->len_mod[1] == 'l')
			mod->arg_text = ft_itoa((long long)arg->data.vdata);
		else
			mod->arg_text = ft_itoa((long)arg->data.vdata);
	}
	else if (mod->len_mod[0] == 'h')
	{
		if (mod->len_mod[1] == 'h')
			mod->arg_text = ft_itoa((signed char)arg->data.vdata);
		else
			mod->arg_text = ft_itoa((short)arg->data.vdata);
	}
	else if (mod->len_mod[0] == 'j' || mod->len_mod[0] == 'z')
		mod->arg_text = ft_itoa((intmax_t)arg->data.vdata);
	else
		catch_error("mod_string_signed error", info);
	signed_prec(mod);
	set_string(mod);
	(mod->res != NULL) ? add_string(info, mod->res) :\
	catch_error("mod_string_signed width_prec error", info);
		
}

void			mod_string_unsigned(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->frmt_spec == 'o')
		mod->arg_text = unsigned_len_mod(arg, mod, 8);
	else if (mod->frmt_spec == 'u')
		mod->arg_text = unsigned_len_mod(arg, mod, 10);
	else if (mod->frmt_spec == 'x' || mod->frmt_spec == 'X')
		mod->arg_text = unsigned_len_mod(arg, mod, 16);
	if (mod->frmt_spec == 'x')
		lower(mod->arg_text);
	signed_prec(mod);
	set_string(mod);
	if (mod->flags && mod->flags->hash == '1' && (mod->frmt_spec == 'x'\
		|| mod->frmt_spec == 'X'))
		add_x(mod);
	add_string(info, mod->res);
}

void			mod_string_point(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	mod->len_mod[0] = 'l';
	mod->arg_text = unsigned_len_mod(arg, mod, 16);
	lower(mod->arg_text);
	set_string(mod);
	add_x(mod);
	add_string(info, mod->res);
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

void			mod_string_float(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->precision == -1)
		mod->precision = 6;
	mod->arg_text = ft_ftoa(arg->data.flt, mod->precision);
	if (mod->flags && mod->flags->plus == '1')
		add_plus(mod);
	set_string(mod);
	add_string(info, mod->res);
}
