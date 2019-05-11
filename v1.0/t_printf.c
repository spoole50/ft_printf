/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:54:29 by spoole            #+#    #+#             */
/*   Updated: 2019/04/18 13:54:30 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_altform   *altinit(void)
{
    t_altform *temp;

    if ((temp = (t_altform*)malloc(sizeof(t_altform))) == NULL)
        catch_error("t_altform struct malloc failure", NULL);
}

t_frmt      *finit(void)
{
    t_frmt *temp;

    if ((temp = (t_frmt*)malloc(sizeof(t_frmt))) == NULL)
        catch_error("t_frmt struct malloc failure", NULL);
    temp->i = 0;
    temp->len = 0;
    temp->type = ' ';
    temp->result = NULL;
    temp->talt = NULL;
    return (temp);
}

t_printf    *init(char *in, va_list ap)
{
    t_printf *temp;

    if ((temp = (t_printf*)malloc(sizeof(t_printf))) == NULL)
        catch_error("t_printf strut malloc failure", NULL);
    temp->in = 0;
    temp->out = 0;
    temp->input = in;
    temp->result = NULL;
    va_copy(temp->args, ap);
    return (temp);
}