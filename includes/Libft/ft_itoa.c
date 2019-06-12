/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:08:42 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:32:01 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_itoa
**	Allocate and returns a “fresh” string ending with ’\0’
**	representing the integer n given as argument.
**	Negative numbers must be supported. If the allocation
**	fails, the function returns NULL.
*/

#include "libft.h"

static int		make_arr(intmax_t n, char **result)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i += 1;
	}
	while ((n / 10) > 0)
	{
		n /= 10;
		i += 1;
	}
	i++;
	*result = (char*)malloc(sizeof(char) * i + 1);
	return (i);
}

static void		work(intmax_t n, int size, char *result)
{
	int		i;
	int		neg;

	i = 1;
	neg = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		neg = 1;
	}
	while ((size - i) > 0)
	{
		result[size - i++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == 0)
		result[size - i] = n + '0';
	result[size] = '\0';
}

char			*ft_itoa(intmax_t n)
{
	int		size;
	char	*result;

	if (n == -9223372036854775808U)
		return ("-9223372036854775808");
	result = NULL;
	size = make_arr(n, &result);
	if (result == NULL)
		return (NULL);
	else
		work(n, size, result);
	return (result);
}
