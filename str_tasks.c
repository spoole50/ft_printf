/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tasks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:54:58 by spoole            #+#    #+#             */
/*   Updated: 2019/05/12 16:54:59 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		next_percent(t_printf *info)
{
	int i;

	i = info->in;
	while (info->input[i] != '\0' && info->input[i] != '%')
		i++;
	return (i - info->in);
}

void    add_string(t_printf *info, char *s1)
{
    char *clean;

    clean = info->result;
	info->tot_writes += ft_strlen(s1);
    info->result = ft_strjoin(info->result, s1);
    free(s1);
    free(clean);
}

void	add_text(t_printf *info, int len)
{
	char	*temp;
	char	*clean;
	int		i;
	
	i = 0;
	if ((temp = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		catch_error("add_text init error", info);
	len += INDEX;
	while (INDEX < len)
		temp[i++] = INPUT[INDEX++];
	temp[i] = '\0';
	clean = info->result;
	info->result = ft_strjoin(info->result, temp);
	info->tot_writes += i;
	free(clean);
	free(temp);
}