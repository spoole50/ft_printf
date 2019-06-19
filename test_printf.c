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
	int s1, s2;
	s1 = s2 = 0;
	// ft_printf("%010.6d\n", 1234);
	// printf("%10.6d\n", 1234);
	// ft_printf("%+ld\n", 2147483648);
	// printf("%+ld\n", 2147483648);
	// ft_printf("Test 1: This %s seeing if string additon works\n", "is a test");
	// ft_printf("Test 2: %s %s\n", "this", "is");
	// ft_printf("Test 3: %s\n", "abc");
	// ft_printf("Test 4: %      s  \n", "this is a string");
	// ft_printf("Test 5: %10s is a string\n", "this");
	// ft_printf("Test 6: %10s is a string\n", "");
	// ft_printf("%.2c\n", NULL);
	// ft_printf("@moulitest: %c", 0);
	// ft_printf("%x", 42);
	// ft_printf("%%");
	// ft_printf("@moulitest: %+.10d\n", 42);
	// printf("@moulitest: %+.10d\n", 42);
	// ft_printf("%05x\n", 42);
	// printf("%05x\n", 42);
	// ft_printf("%+++d\n", 534);
	// printf("%+++d\n", 534);
	// ft_printf("%05.1u %3.4hu %-4.7u\n", 45, (unsigned short)-1789, 147);
	// printf("%05.1u %3.4hu %-4.7u\n", 45, (unsigned short)-1789, 147);
	// s1 = printf("% .0i\n", 10);
	// s2 = ft_printf("% .0i\n", 10);
	// char test[] = "This is a test";
	// printf("%p\n", &test);
	// ft_printf("%p\n", &test);
	// ft_printf("%05.1u %3.4hu %-4.7u, 45\n", (unsigned short)-1789, 147);
	// printf("%05.1u %3.4hu %-4.7u, 45\n", (unsigned short)-1789, 147);
	// ft_printf("%#o\n", 1000);
	// printf("%#o\n", 1000);
	// s1 = printf("%- 10.5lf\n", 1.0);
	// s2 = ft_printf("%- 10.5lf\n", 1.0);
	// s1 = printf("%-  10.4%\n");
	// s2 = ft_printf("%-  10.4%\n");
	// s1 = printf("%10.0%\n");
	// s2 = ft_printf("%10.0%\n");
	// s1 = printf("%-05d\n", -42);
	// s2 = ft_printf("%-05d\n", -42);
	// s1 = printf("%#0.8x\n", 42); 
	// s2 = ft_printf("%#0.8x\n", 42);
	// s1 = printf("%#x\n", 0);
	// s2 = ft_printf("%#x\n", 0);
	// s1 = printf("%#-08x\n", 42);
	// s2 = ft_printf("%#-08x\n", 42);
	// s1 = printf("%#08x\n", 42);
	// s2 = ft_printf("%#08x\n", 42);
	// s1 = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s2 = ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s1 = printf("%4.15d\n", 42);
	// s2 = ft_printf("%4.15d\n", 42);
	// s1 = printf("%lld\n", -9223372036854775808);
	// s2 = ft_printf("%lld\n", -9223372036854775808);
	// s1 = printf("% d\n", 42);
	// s2 = ft_printf("% d\n", 42);
	// s1 = printf("% 10.5d\n", 4242);
	// s2 = ft_printf("% 10.5d\n", 4242);
	// s1 = printf("%0+5d\n", 42);
	// s2 = ft_printf("%0+5d\n", 42);
	// s1 = printf("%+10.5d\n", 4242);
	// s2 = ft_printf("%+10.5d\n", 4242);
	// s1 = printf("% d\n", 42);
	// s2 = ft_printf("% d\n", 42);
	// s1 = printf("%.5f\n", 123.456789);
	// s2 = ft_printf("%.5f\n", 123.456789);
	// s1 = printf("% d\n", 42);
	// s2 = ft_printf("% d\n", 42);
	// s1 = printf("%-5d\n", -42);
	// s2 = ft_printf("%-5d\n", -42);
	// s1 = printf("%03.2d\n", -1);
	// s2 = ft_printf("%03.2d\n", -1);
	// s1 = printf("@moulitest: %.10d\n", -42);
	// s2 = ft_printf("@moulitest: %.10d\n", -42);
	// s1 = printf("%+u\n", 4294967295);;
	// s2 = ft_printf("%+u\n", 4294967295);
	// s1 = printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// s2 = ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// s1 = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s2 = ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s1 = printf("@moulitest: %.o %.0o\n", 0, 0);
	// s2 = ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	// s1 = printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// s2 = ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// s1 = printf("@moulitest: %5.o %5.0o\n", 0, 0);
	// s2 = ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	// s1 = printf("%-2i\n", -7);
	// s2 = ft_printf("%-2i\n", -7);
	// s1 = printf("hello % .d this is a test\n", 0);
	// s2 = ft_printf("hello % .d this is a test\n", 0);
	// s1 = printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	// s2 = ft_printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	// s1 = printf("%U\n", 4294967295);
	// s2 = ft_printf("%U\n", 4294967295);
	// s1 = printf("%hU\n", 4294967296);
	// s2 = ft_printf("%hU\n", 4294967296);
	// s1 = printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	// s2 = ft_printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	// s1 = printf("toto %###.0o%#.O et %#.1o !\n", 0, 0, 0);
	// s2 = ft_printf("toto %###.0o%#.O et %#.1o !\n", 0, 0, 0);
	// s1 = printf("%###.0o\n", 0);
	// s2 = ft_printf("%###.0o\n", 0);
	// s1 = printf("%###.0o%#.O\n", 0 ,0);
	// s2 = ft_printf("%###.0o%#.O\n", 0 ,0);
	// s1 = printf("%#6o\n", 2500);
	// s2 = ft_printf("%#6o\n", 2500);
	// s1 = printf("@moulitest: %.o %.0o\n", 0, 0);
	// s2 = ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	// s1 = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s2 = ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// s1 = printf("%#-08x\n", 42);
	// s2 = ft_printf("%#-08x\n", 42);
	// s1 = printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	// s2 = ft_printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	// s1 = printf("osef ! %#9llX et %-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	// s2 = ft_printf("osef ! %#9llX et %-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	// s1 = printf("%#9llX\n", (unsigned long long)-1248759650);
	// s2 = ft_printf("%#9llX\n", (unsigned long long)-1248759650);
	// s1 = printf("%#04hX\n", (unsigned short)0);
	// s2 = printf("%#04hX\n", (unsigned short)0);
	// s1 = printf("%0#10.0x %0#x\n", 12345, 0);
	// s2 = ft_printf("%0#10.0x %0#x\n", 12345, 0);
	// s1 = printf("%p\n", NULL);
	// s2 = ft_printf("%p\n", NULL);
	// int i = 123;
	// s1 = printf("%-25p\n", &i);
	// s2 = ft_printf("%-25p\n", &i);
	// s1 = printf("%c\n", '\0');
	// s2 = ft_printf("%c\n", '\0');
	// s1 = printf("%0#10.0x\n", 0);
	// s2 = ft_printf("%0#10.0x\n", 0);
	// s1 = printf("%c\n", -21);
	// s2 = ft_printf("%c\n", -21);
	// s1 = printf("%.4f\n", 123.456798);
	// s2 = ft_printf("%.4f\n", 123.456798);
	// s1 = printf("%%\n");
	// s2 = ft_printf("%%\n");
	//s1 = printf("{%3c}\n", 0);
	//s2 = ft_printf("{%3c}\n", 0);
	// int strlen = 5;
	// s1 = printf("{%-13p}\n", &strlen);
	// s2 = ft_printf("{%-13p}\n", &strlen);
	// s1 = printf("%#-08x\n", 42);
	// s2 = ft_printf("%#-08x\n", 42);
	// s1 = printf("{%10R}\n");
	// s2 = ft_printf("{%10R}\n");
	// s1 = printf("%4.15d\n", -42);
	// s2 = ft_printf("%4.15d\n", -42);
	//s1 = printf("%.p, %.0p\n", 0, 0);
	//s2 = ft_printf("%.p, %.0p\n", 0, 0);
	//s1 = printf("%.5p\n", 0);
	//s2 = ft_printf("%.5p\n", 0);
	s1 = printf("%2.9p\n", 1234);
	s2 = ft_printf("%2.9p\n", 1234);
	//s1 = printf("%9.2p\n", 1234);
	//s2 = ft_printf("%9.2p\n", 1234);
	//s1 = printf("%");
	ft_printf("sysSize:%d ftSize:%d Match:%c\n", s1, s2, (s1==s2)?'Y':'N');
	return (0);
}
