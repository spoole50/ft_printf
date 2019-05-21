/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:06:42 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:28:34 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strjoin
**	Allocates and returns a “fresh” string ending
**	with ’\0’, result of the concatenation of s1 and s2.
**	If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*res_start;
	int		test;

	test = ft_strlen(s1) + ft_strlen(s2);
	if ((result = (char*)ft_memalloc(test + 1)) == NULL)
		return (NULL);
	else
	{
		res_start = result;
		while (s1 != NULL && *s1)
			*result++ = *s1++;
		while (s2 != NULL && *s2)
			*result++ = *s2++;
		*result = '\0';
		return (res_start);
	}
}
