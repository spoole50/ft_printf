/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:21:53 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:21:55 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_empty(char q)
{
	return (q == '0' || q == ' ');
}

int		is_conv(char q)
{
	return (is_signed(q) || is_unsigned(q)\
			|| is_text(q) || is_float(q));
}

int		is_flag(char q)
{
	return (q == '#' || q == '0' || q == '-' || q == '+' || q == ' ');
}

int		is_len_mod(char *str, int i)
{
	if (str[i] == 'l' || str[i] == 'L')
	{
		if (str[i + 1] == 'l')
			return (2);
		return (1);
	}
	else if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			return (2);
		return (1);
	}
	else if (str[i] == 'j' || str[i] == 'z')
		return (1);
	return (0);
}

int		is_invalid_conv_spec(char *str, int i)
{
	int x;

	x = i;
	while (str[x] != '\0' && !(ft_isalpha(str[x])) && !(is_conv(str[x])))
		x++;
	x += is_len_mod(str, x);
	if (is_conv(str[x]))
		return (x - i);
	else if (str[x] == '\0')
		return (0);
	else
		return (-1);
}
