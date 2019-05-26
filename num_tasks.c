/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_tasks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:05:20 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:45:01 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			has_sign(char *s1)
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

void		lower(char *str)
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

void		add_x(t_mod *mod)
{
	int		size;
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	size = ft_strlen(mod->arg_text) + 3;
	tmp = (char*)ft_memalloc(sizeof(char) * size);
	tmp[i++] = '0';
	tmp[i++] = (mod->frmt_spec == 'X') ? 'X' : 'x';
	while (i < size)
		tmp[i++] = mod->arg_text[x++];
	free(mod->arg_text);
	mod->arg_text = tmp;
}

char		*unsigned_len_mod(t_arg_node *arg, t_mod *mod, int base)
{
	char	*temp;

	temp = NULL;
	if (mod->len_mod[0] == 'l')
	{
		if (mod->len_mod[1] == 'l')
			temp = ft_itoab_unsigned((unsigned long long)arg->data, base);
		else
			temp = ft_itoab_unsigned((unsigned long)arg->data, base);
	}
	else if (mod->len_mod[0] == 'h')
	{
		if (mod->len_mod[1] == 'h')
			temp = ft_itoab_unsigned((unsigned char)arg->data, base);
		else
			temp = ft_itoab_unsigned((unsigned short)arg->data, base);
	}
	else
		temp = ft_itoab_unsigned((unsigned int)arg->data, base);
	return (temp);
}
