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

void			ftoa_help(t_ftoa *var, int precision)
{
	if ((*var).neg == 1)
		(*var).res[(*var).i++] = '-';
	if (((*var).sub_z == 1 || (*var).clean[0] == '0') && precision != 0)
		(*var).res[(*var).i++] = '0';
	while (*((*var).temp) != '\0' && (*var).i < (*var).size)
	{
		if ((*var).i == (*var).dot)
			(*var).res[(*var).i++] = '.';
		else if ((*var).size - (*var).i - 1 > (*var).str_len &&\
		((*var).sub_z == 1 || (*var).clean[0] == '0'))
			(*var).res[(*var).i++] = '0';
		else
			(*var).res[(*var).i++] = *((*var).temp)++;
	}
	free((*var).clean);
}

void			str_set(t_ftoa *var, int precision)
{
	(*var).temp = ft_itoab_unsigned((*var).tmp, 10);
	(*var).clean = (*var).temp;
	(*var).str_len = ft_strlen((*var).temp);
	(*var).size = ((*var).str_len <= precision)\
	? precision + (*var).sub_z : (*var).str_len;
	if (precision == 0)
	{
		(*var).size += ((*var).neg == 1) ? 2 : 1;
		(*var).dot = -1;
		(*var).sub_z = 0;
	}
	else
	{
		(*var).size += ((*var).neg == 1) ? 3 : 2;
		(*var).size += ((*var).temp[0] == '0') ? 1 : 0;
		(*var).dot = ((*var).temp[0] == '0')\
		? 1 : ((*var).size - precision) - 2;
	}
	(*var).res = (char*)ft_memalloc(sizeof(char) * ((*var).size));
}

char			*ft_ftoa(long double num, int precision)
{
	t_ftoa		var;

	var.size = precision;
	var.i = 0;
	var.neg = 0;
	var.sub_z = 0;
	if ((num > 0 && num < 1) || (num < 0 && num > -1))
		var.sub_z = 1;
	while (var.size--)
		num *= 10;
	if (num < 0)
	{
		var.tmp = (num - 0.5) * -1;
		var.neg = 1;
	}
	else
		var.tmp = num + 0.5;
	str_set(&var, precision);
	ftoa_help(&var, precision);
	return (var.res);
}
