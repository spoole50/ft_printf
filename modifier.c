/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:21:30 by spoole            #+#    #+#             */
/*   Updated: 2019/05/26 00:00:34 by spoole           ###   ########.fr       */
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

void		handle_len_mod(t_printf *info, t_mod *mod)
{
	int		i;

	i = 0;
	if (mod->len_mod[i] == '0')
	{
		while (!(is_conv(INPUT[INDEX])) && i < 2)
			mod->len_mod[i++] = INPUT[INDEX++];
	}
	else
		while (!(is_conv(INPUT[INDEX])))
			INDEX++;
}

void		validate_conv_spec(t_printf *info, t_mod *mod)
{
	int	len;
	int	i;

	i = 0;
	INDEX++;
	if ((len = is_invalid_conv_spec(INPUT, INDEX)) == -1)
		catch_error("Invalid Conversion Specification", info);
	mod->frmt_spec = INPUT[INDEX + len];
}

void		parse_spec(t_printf *info, t_mod *mod)
{
	char x;

	x = mod->frmt_spec;
	if (x == 'D' || x == 'O' || x == 'U')
	{
		mod->frmt_spec = ft_tolower(x);
		mod->len_mod[0] = 'l';
	}
	while (!is_conv(INDEX[INPUT]))
	{
		if (is_flag(INPUT[INDEX]))
			handle_flags(info, mod);
		else if (ft_isnum(INPUT[INDEX]))
			mod->min_wid = read_number(info);
		else if (INPUT[INDEX] == '.')
			handle_precision(info, mod);
		else if (is_len_mod(INPUT, INDEX))
			handle_len_mod(info, mod);
		else
			INDEX++;
	}
	INDEX++;
}

void		handle_mod(t_printf *info, va_list ap)
{
	t_mod	*mod;

	mod = t_mod_init(info);
	validate_conv_spec(info, mod);
	if (is_other(mod->frmt_spec))
		mod->arg_text = "%";
	else
	{
		if (check_arg(INPUT, INDEX))
			mod->arg_num = handle_mult_arg(info, ap, mod->frmt_spec);
		else
			mod->arg_num = add_next_arg(info, ap, mod->frmt_spec);
	}
	parse_spec(info, mod);
	if (is_text(mod->frmt_spec) || is_other(mod->frmt_spec))
		mod_string_char(info, mod);
	else if (mod->frmt_spec == 'p')
		mod_string_point(info, mod);
	else if (is_signed(mod->frmt_spec))
		mod_string_signed(info, mod);
	else if (is_unsigned(mod->frmt_spec))
		mod_string_unsigned(info, mod);
	else if (is_float(mod->frmt_spec))
		mod_string_float(info, mod);
	clean_tmod(mod);
}