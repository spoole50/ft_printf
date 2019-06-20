/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:33:10 by spoole            #+#    #+#             */
/*   Updated: 2019/04/01 12:33:11 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "Libft/libft.h"

typedef struct  s_altform
{
    char         hash;
    char         zero;
    char         plus;
    char         minus;
}               t_altform;

typedef	struct 	s_frmt
{
	int			i;
    int         len;
	char		type;
	char		*result;
    t_altform   *talt;
}				t_frmt;

typedef struct  s_printf
{
	int     	in;
	int     	out;
	char		*input;
	char    	*result;
	va_list		args;
}				t_printf;

int	    	ft_printf(const char *input, ...);
int	    	ft_vprintf(const char *input, va_list ap);
int	    	ft_asprintf(char **str, const char *input, ...);
int	    	ft_vasprintf(char **str, const char *input, va_list ap);
void 		validate_mod(t_printf *info);
t_printf    *init(char *in, va_list ap);
t_frmt      *finit(void);

#endif
