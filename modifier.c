/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:21:30 by spoole            #+#    #+#             */
/*   Updated: 2019/05/01 21:21:31 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int     is_conv(char q)
{
    return (q == 'd' || q == 'i' || q == 'o' || q == 'u' || q == 'x' || q == 'X' || q == 'f' || q == 's');
}

int     is_flag(char q)
{
    return (q == '#' || q == '0' || q == '-' || q == '+');
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

char     is_invalid_conv_spec(char *str, int i)
{
    while (!(ft_isalpha(str[i])))
        i++;
    i += is_len_mod(str, i);    
    if (is_conv(str[i]))
        return (str[i]);
    else
        return ('E');
}

int     check_arg(char *str, int i)
{
    if (ft_isnum(str[i]))
    {
        while (ft_isnum(str[i]))
            i++;
        if (str[i] == '$')
            return (1);
    }
    return (0);
}

void    handle_mod(t_printf *info, va_list ap)
{
    t_mod *temp;

    temp = t_mod_init(info);
    info->input[info->in++];
    if ((temp->frmt_spec = invalid_conv_spec(INPUT, INDEX)) == 'E')
        catch_error("Invalid Conversion Specification", info);
    if (check_arg(INPUT, INDEX))
        //handle_arg(info, ap);
    if (is_flag(INPUT[INDEX]))
        //handle_flags(info);
    if (is_min_width());
        //handle_min_width
}