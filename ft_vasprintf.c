/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:19:52 by spoole            #+#    #+#             */
/*   Updated: 2019/04/01 15:19:54 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


void    catch_error(char *s1, t_printf *clean)
{
    if (clean != NULL)
    {
        free(clean);
    }
    ft_putstr(s1);
    exit(EXIT_FAILURE);
}

int		next_percent(t_printf *info)
{
	int i;

	i = info->in;
	while (info->input[i] != '\0' && info->input[i] != '%')
		i++;
	return (i - info->in);
}

int		ft_vasprintf(char **str, const char *input, va_list ap)
{
	t_printf	*info;
	int			count;

	info = t_printf_init((char*)input);
	count = 0;
	if (input == NULL)
		catch_error("Null/invalid input string", NULL);
	while (info->input[info->in] != '\0')
	{
		count = next_percent(info);
		if (count > 0)
		{
			str_node_init(info);
			fill_node(info, count);
		}
		else
			handle_mod(info, ap);		
	}
	*str = build_str(info);
	return (count);
}