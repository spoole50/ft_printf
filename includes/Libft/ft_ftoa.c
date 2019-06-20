/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:21:17 by spoole            #+#    #+#             */
/*   Updated: 2019/05/22 14:21:18 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ftoa_help(t_ftoa var)
{
	if (var.neg == 1)
		var.res[var.i++] = '-';
	while (*(var.temp) != '\0')
	{
		if (var.i == var.dot)
			var.res[var.i++] = '.';
		else
			var.res[var.i++] = *(var.temp)++;
	}
	free(var.clean);
	return (var.res);
}

char			*ft_ftoa(double num, int precision)
{
	t_ftoa	var;

	var.size = precision;
	var.i = 0;
	var.neg = 0;
	while (var.size--)
		num *= 10;
	if (num < 0)
	{
		var.tmp = (num - 0.5) * -1;
		var.neg = 1;
	}
	else
		var.tmp = num + 0.5;
	var.temp = ft_itoab_unsigned(var.tmp, 10);
	var.clean = var.temp;
	var.size = ft_strlen(var.temp);
	var.size += (var.neg == 1) ? 3 : 2;
	var.res = (char*)ft_memalloc(sizeof(char) * (var.size));
	var.dot = (var.size - precision) - 2;
	return (ftoa_help(var));
}
