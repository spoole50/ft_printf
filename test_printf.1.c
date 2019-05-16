/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:35:00 by spoole            #+#    #+#             */
/*   Updated: 2019/04/17 10:38:43 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int		main(void)
{
	/*ft_printf("Test 1: This %s seeing if string additon works\n", "is a test");
	ft_printf("Test 2: %s %s\n", "this", "is");
	ft_printf("Test 3: %s\n", "abc");
	ft_printf("Test 4: %      s  \n", "this is a string");
	ft_printf("Test 5: %10s is a string\n", "this");
	ft_printf("Test 6: %10s is a string", "");*/
	ft_printf("%.2c", NULL);
	ft_putchar((char)0);
	exit(0);
}
