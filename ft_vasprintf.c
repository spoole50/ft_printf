/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:19:52 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:17:04 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				has_sign(char *s1)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void			lower(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ft_tolower(str[i]);
		i++;
	}
}

int				ft_vasprintf(char **str, const char *input, va_list ap)
{
	t_printf	*info;
	int			count;

	info = t_printf_init((char*)input);
	count = 0;
	if (input == NULL)
		return (-1);
	while (info->input[info->in] != '\0')
	{
		count = next_percent(info);
		if (count > 0)
			add_text(info, count);
		else
			handle_mod(info, ap);
	}
	*str = info->result;
	count = info->tot_writes;
	clean_tprintf(info);
	return (count);
}
