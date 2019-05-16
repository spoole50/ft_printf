/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:07:12 by spoole            #+#    #+#             */
/*   Updated: 2019/05/11 19:07:13 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int     is_space(char q)
{
    return (q == 32 || q == 11 || q == 9);
}


int     is_signed(char q)
{
    return (q == 'd' || q == 'i');
}

int     is_unsigned(char q)
{
    return (q == 'o' || q == 'u' || q == 'x' || q == 'X');
}

int     is_text(char q)
{
    return (q == 's' || q == 'c');
}
int     is_float(char q)
{
    return (q == 'f');
}

int     is_other(char q)
{
    return (q == '%');
}
int     is_conv(char q)
{
    return (is_signed(q) || is_unsigned(q) || is_text(q) || is_float(q) || is_other(q));
}

int     is_flag(char q)
{
    return (q == '#' || q == '0' || q == '-' || q == '+');
}

int     check_arg(char *str, int i)
{
    if (ft_isnum(str[i]) || is_space(str[i]))
    {
        while (ft_isnum(str[i]) || is_space(str[i]))
            i++;
        if (str[i] == '$')
            return (1);
    }
    return (0);
}

int     is_len_mod(char *str, int i)
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
    return (0);
}

int     is_invalid_conv_spec(char *str, int i)
{
    int x;

    x = i;
    while (!(ft_isalpha(str[x])))
        x++;
    i += is_len_mod(str, x);    
    if (is_conv(str[x]))
        return (x - i);
    else
        return (-1);
}