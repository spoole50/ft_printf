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
	//ft_printf("%010.6d\n", 1234);
	//printf("%10.6d\n", 1234);
	//ft_printf("%+ld\n", 2147483648);
	//printf("%+ld\n", 2147483648);
	//ft_printf("Test 1: This %s seeing if string additon works\n", "is a test");
	//ft_printf("Test 2: %s %s\n", "this", "is");
	//ft_printf("Test 3: %s\n", "abc");
	//ft_printf("Test 4: %      s  \n", "this is a string");
	//ft_printf("Test 5: %10s is a string\n", "this");
	//ft_printf("Test 6: %10s is a string\n", "");
	//ft_printf("%.2c\n", NULL);
	//ft_printf("@moulitest: %c", 0);
	//ft_printf("%x", 42);
	//ft_printf("%%");
	//ft_printf("@moulitest: %+.10d\n", 42);
	//printf("@moulitest: %+.10d\n", 42);
	//ft_printf("%05x\n", 42);
	//printf("%05x\n", 42);
	//ft_printf("%+++d\n", 534);
	//printf("%+++d\n", 534);
	//ft_printf("%05.1u %3.4hu %-4.7u\n", 45, (unsigned short)-1789, 147);
	//printf("%05.1u %3.4hu %-4.7u\n", 45, (unsigned short)-1789, 147);
	//ft_printf("%.0i\n", 10);
	//printf("%.0i\n", 10);
	//char test[] = "This is a test";
	//printf("%p\n", &test);
	//ft_printf("%p\n", &test);
	//ft_printf("%05.1u %3.4hu %-4.7u, 45\n", (unsigned short)-1789, 147);
	//printf("%05.1u %3.4hu %-4.7u, 45\n", (unsigned short)-1789, 147);
	ft_printf("%#o\n", 1000);
	printf("%#o\n", 1000);
	return (0);
}
