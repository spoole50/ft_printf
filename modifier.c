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

int			validate_conv_spec(t_printf *info, t_mod *mod)
{
	int		len;
	int		i;

	i = 0;
	INDEX++;
	if ((len = is_invalid_conv_spec(INPUT, INDEX)) == -1)
		return (-1);
	if (INPUT[INDEX + len - 1] == 'L')
		mod->len_mod[0] = 'L';
	mod->frmt_spec = INPUT[INDEX + len];
	return (0);
}

void		parse_spec(t_printf *info, t_mod *mod)
{
	char	x;

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

void		create_arg(t_printf *info, t_mod *mod, va_list ap)
{
	if (check_arg(INPUT, INDEX))
		mod->arg_num = handle_mult_arg(info, ap,\
		mod->frmt_spec, mod->len_mod[0]);
	else
		mod->arg_num = add_next_arg(info, ap,\
		mod->frmt_spec, mod->len_mod[0]);
}

int			handle_mod(t_printf *info, va_list ap)
{
	t_mod	*mod;
	int		valid;

	mod = t_mod_init();
	if ((valid = validate_conv_spec(info, mod)) == -1\
	|| !is_conv(mod->frmt_spec))
	{
		free(mod);
		if (valid == -1)
			return (-1);
		else
			return (0);
	}
	if (mod->frmt_spec == '%')
		mod->arg_text = "%";
	else
		create_arg(info, mod, ap);
	parse_spec(info, mod);
	sort_spec(info, mod);
	//clean_tmod(mod);
	return (0);
}
