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
	char				space;
}                       t_flags;

typedef struct			s_mod
{
	int					min_wid;
	int					arg_num;
	int					precision;
	int					cur_size;
	int					res_i;
	char				frmt_spec;
	char				len_mod[2];
	char				*arg_text;
	char				*res;
	t_flags				*flags;
}						t_mod;

typedef	struct 			s_arg_node
{
	int					index;
	void 				*data;
	struct s_arg_node	*next;
}						t_arg_node;

typedef struct  		s_printf
{
	int					tot_writes;
	int					in;
    int                 cur_args;
	int					max_args;
	char				*input;
	char				*result;
	t_arg_node			*arg_begin;
}						t_printf;

/*
** Printf main function definition
** ft_printf.c
*/
int	    		ft_printf(const char *input, ...);
int	    		ft_vprintf(const char *input, va_list ap);
int	    		ft_asprintf(char **str, const char *input, ...);

/*
** ft_vasprintf main program entry functions
** ft_vasprintf.c
*/
int	    		ft_vasprintf(char **str, const char *input, va_list ap);
void        	catch_error(char *s1, t_printf *clean);

/*
** String Task Functions
** str_tasks.c
*/
int		next_percent(t_printf *info);
void    add_string(t_printf *info, char *s1);
void	add_text(t_printf *info, int len);

/*
** General Node Functions
**	node_init.c
*/
t_flags         *t_flags_init(t_printf *info, t_mod *mod);
t_mod           *t_mod_init(t_printf *info);
void            clean_tprintf(t_printf *info);
t_printf        *t_printf_init(char *in);

/*
** Argument Node Functions
** arg_node.c
*/
int         handle_mult_arg(t_printf *info, va_list ap);
int         add_next_arg(t_printf *info, va_list ap);
void        arg_node_init(t_printf *info, void *indata);

/*
** Various check functions
** is_check_functions.c
*/
int     is_space(char q);
int     is_signed(char q);
int     is_unsigned(char q);
int     is_text(char q);
int     is_float(char q);
int     is_other(char q);
int     is_conv(char q);
int     is_flag(char q);
int     is_len_mod(char *str, int i);
int	    is_invalid_conv_spec(char *str, int i);
int     check_arg(char *str, int i);

/*
** Create Modification String
** mod_string.c
*/
void    mod_string_char(t_printf *info, t_mod *mod);
void    mod_string_signed(t_printf *info, t_mod *mod);
void    mod_string_unsigned(t_printf *info, t_mod *mod);
void    mod_string_float(t_printf *info, t_mod *mod);

/*
** Modification Checks
** modifiers.c
*/
int    			read_number(t_printf *info);
void    		handle_mod(t_printf *info, va_list ap);
void    		set_string(t_mod *mod);

#endif
