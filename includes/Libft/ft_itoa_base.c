/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:32:30 by spoole            #+#    #+#             */
/*   Updated: 2019/05/20 16:32:31 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoab_signed(intmax_t num, int base)
{
	char		*res;
	char		*tab;
	int			size;
	int			neg;
	intmax_t	temp;

	size = 0;
	neg = 0;
	tab = "0123465789ABCDEF";
	(num < 0 && base == 10) ? (neg = 1) : (neg);
	(neg == 1) ? (num *= -1) : (num = num);
	temp = num;
	while (temp /= base)
		size++;
	size = size + neg + 1;
	res = (char*)ft_memalloc(size);
	(neg == 1) ? (res[0] = '-') : (res[0]);
	while (size > 0)
	{
		res[--size] = tab[num % base];
		num /= base;
	}
	return (res);
}

char			*ft_itoab_unsigned(uintmax_t num, int base)
{
	char		*res;
	char		*tab;
	int			size;
	uintmax_t	temp;

	size = 1;
	tab = "0123456789ABCDEF";
	temp = num;
	while (temp /= base)
		size++;
	res = (char*)ft_memalloc(sizeof(char) * (size + 1));
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size--] = tab[num % base];
		num /= base;
	}
	return (res);
}
