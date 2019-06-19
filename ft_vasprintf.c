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

void			catch_error(char *s1, t_printf *clean)
{
	//clean_tprintf(clean);
	//ft_putstr(s1);
	s1++;
	ft_putstr("\n");
	clean->tot_writes = -1;
	if (clean->result != NULL)
		free(clean->result);
	clean->result = "";
	//exit(EXIT_FAILURE);
}

int				ft_vasprintf(char **str, const char *input, va_list ap)
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
			add_text(info, count);
		else
			handle_mod(info, ap);
	}
	*str = info->result;
	count = info->tot_writes;
	clean_tprintf(info);
	return (count);
}
