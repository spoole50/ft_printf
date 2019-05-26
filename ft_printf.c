/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:45:36 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:15:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
**	printf comments
*/

int			ft_printf(const char *input, ...)
{
	va_list	ap;
	char	*output;
	int		result;
	int		i;

	result = 0;
	i = 0;
	output = NULL;
	va_start(ap, input);
	result = ft_vasprintf(&output, input, ap);
	va_end(ap);
	while (i < result)
		ft_putchar(output[i++]);
	free(output);
	return (result);
}

int			ft_vprintf(const char *input, va_list ap)
{
	char	*output;
	int		result;

	result = 0;
	output = NULL;
	result = ft_vasprintf(&output, input, ap);
	ft_putstr(output);
	free(output);
	return (result);
}

int			ft_asprintf(char **str, const char *input, ...)
{
	va_list ap;
	int		result;

	result = 0;
	va_start(ap, input);
	result = ft_vasprintf(str, input, ap);
	va_end(ap);
	return (result);
}
