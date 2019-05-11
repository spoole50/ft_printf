/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:36:30 by spoole            #+#    #+#             */
/*   Updated: 2019/05/09 11:36:33 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void    test_check_arg(void)
{
    int res[5];

    res[0] = check_arg("123$", 0) == 1;
    res[1] = check_arg("1a3", 0) == 0;
    res[2] = check_arg("Test%12$", 5) == 1;
    res[3] = check_arg("0000$", 0) == 1;
    res[4] = check_arg("as$", 0) == 0;
    for(int x = 0; x < 5; x++)
        printf("Function: check_arg Test:#%d %s\n", x, (res[x] == 1) ? "Pass" : "Fail");
    printf("\n");
}

void    test_is_len_mod(void)
{
    int res[10];

    res[0] = is_len_mod("l", 0) == 1;
    res[1] = is_len_mod("hh", 0) == 2;
    res[2] = is_len_mod("ll", 0) == 2;
    res[3] = is_len_mod("L", 0) == 1;
    res[4] = is_len_mod("qwer", 0) == 0;
    res[5] = is_len_mod("\43", 0) == 0;
    res[6] = is_len_mod("000", 0) == 0;
    res[7] = is_len_mod("\t\t\t\t", 0) == 0;
    res[8] = is_len_mod("\xa", 0) == 0;
    res[9] = is_len_mod("~!@#@#$", 0) == 0;
    for(int x = 0; x < 10; x++)
        printf("Function: is_len_mod Test:#%d %s\n", x, (res[x] == 1) ? "Pass" : "Fail");
    printf("\n");
}

void    test_invalid_conv_spec(void)
{
    int res[5];

    res[0] = invalid_conv_spec("d", 0) == 'd';
    res[1] = invalid_conv_spec("s", 0) == 's';
    res[2] = invalid_conv_spec("%2$25.500lld", 1) == 'd';
    res[3] = invalid_conv_spec("0000", 0) == 'E';
    res[4] = invalid_conv_spec("1", 0) == 'E';
    for(int x = 0; x < 5; x++)
        printf("Function: invalid_conv_spec Test:#%d %s\n", x, (res[x] == 1) ? "Pass" : "Fail");
    printf("\n");
}

int     main(void)
{
    test_check_arg();
    test_is_len_mod();
    test_invalid_conv_spec();
    return (0);
}
