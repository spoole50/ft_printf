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

char    *ft_ftoa(long double num, int precision)
{
    char        *res;
    char        *temp;
    uintmax_t   tmp;
    int         neg;
    int         size;
    int         dot;
    int         i;

    size = precision;
    i = 0;
    neg = 0;
    while (size--)
        num *= 10;
    if (num < 0)
    {
        tmp = num * -1;
        neg = 1;   
    }
    else
        tmp = num;
    temp = ft_itoab_unsigned(num, 10);
    size = ft_strlen(temp);
    size += (neg == 1) ? 3 : 2;
    res = (char*)ft_memalloc(sizeof(char) * (size));
    dot = (neg == 1) ? ((size - precision) - 3) : ((size - precision) - 2);
    (neg == 1) ? (res[i++] = '-') : (res[i] = '\0');
    while (*temp != '\0')
    {
        if (i == dot)
            res[i++] = '.';
        else
            res[i++] = *temp++; 
    }
    free(temp);
    return (res);
}