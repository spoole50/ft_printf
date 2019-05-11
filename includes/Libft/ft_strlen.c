/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:58:26 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:26:46 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strlen
**	Calcualtes the length of string (char *s)
**	returns the number of characters preceding
**	the NULL terminator.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*info;

	info = (char*)s;
	while (info != NULL && *info != '\0')
		info++;
	return (info - s);
}
