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

# define INPUT info->input
# define INDEX info->in

typedef struct          s_flags
{
    char                hash;
    char                zero;
    char                plus;
    char                minus;
}                       t_flags;

typedef struct			s_mod
{
	int					min_wid;
	int					cur_size;
	char				frmt_spec;
}						t_mod;

typedef	struct 			s_arg_node
{
	int					index;
	void 				*data;
	struct s_arg_node	*next;
}						t_arg_node;

typedef struct 			s_str_node
{
	int					i;
	char				*str;
	struct s_str_node	*next;
}						t_str_node;

typedef struct  		s_printf
{
	int					len;
	int					in;
    int                 cur_args;
	int					max_args;
	char				*input;
	t_str_node			*str_begin;
	t_arg_node			*arg_begin;
}						t_printf;

int	    		ft_printf(const char *input, ...);
int	    		ft_vprintf(const char *input, va_list ap);
int	    		ft_asprintf(char **str, const char *input, ...);
int	    		ft_vasprintf(char **str, const char *input, va_list ap);
void        	catch_error(char *s1, t_printf *clean);
void			arg_node_init(t_printf *info, void *indata);
void			str_node_init(t_printf *info);
t_printf        *t_printf_init(char *in);
char            *build_str(t_printf *info);
void    		handle_mod(t_printf *info, va_list ap);
void        	fill_node(t_printf *info, int len);
t_mod           *t_mod_init(t_printf *info);

/**
 * Modification Checks
 * modifiers.c
 **/
int     		check_arg(char *str, int i);
int     		is_len_mod(char *str, int i);
char     		invalid_conv_spec(char *str, int i);

#endif