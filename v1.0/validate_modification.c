/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_modification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:30:49 by spoole            #+#    #+#             */
/*   Updated: 2019/04/24 20:30:50 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_flag(char f)
{
	return (f == 'd' || f == 'i' || f == 'o' || f == 'u' || f == 'x' || f == 'X' || f == 'f');
}

int		is_form(char f)
{
	return (f == '#' || f == '0' || f == '-' || f == '+');
}

char    find_tc(char *input, int i)
{
    while (input[i] != '\0')
    {
        if (is_flag(input[i]))
            return (input[i]);
        i++;
    }
    return ('1');
}

void    altern_form(t_printf *info, t_frmt *finfo)
{
    if (info->input[info->in] == '#')
    {
        if (finfo->type == 'o')
            finfo->result[finfo->i++] = '0';
        else if (finfo->type == 'x' || finfo->type == 'X')
        {
            finfo->result[finfo->i++] = '0';
            finfo->result[finfo->i++] = (finfo->type == 'x') ? 'x' : 'X';
        }
    }
}

void 	validate_mod(t_printf *info)
{
    t_frmt *finfo;

    if ((finfo = finit()) == NULL)
        catch_error("Failed init on t_frmt struct", info);
        return;
    info->in++;
    if ((finfo->type = find_tc(info->input, info->in)) == '1')
        catch_error("No valid type found", info);
        return;
    
	if (is_form(info->input[info->in]))
        altern_form(info, finfo);	
}