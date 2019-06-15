/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:07:12 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:21:26 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_space(char q)
{
	return (q == 32 || q == 11 || q == 9);
}

int		is_signed(char q)
{
	return (q == 'd' || q == 'i' || q == 'D');
}

int		is_unsigned(char q)
{
	return (q == 'o' || q == 'u' || q == 'x' || q == 'X' || q == 'p' || q == 'O' || q == 'U');
}

int		is_text(char q)
{
	return (q == 's' || q == 'c' || q == 'S' || q == 'C');
}

int		is_float(char q)
{
	return (q == 'f');
}
