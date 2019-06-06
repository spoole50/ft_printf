#include "includes/ft_printf.h"

char    *ft_ftoa(long double num, int pre);

int     main(void)
{
    float temp = 123.456;
    char *test = ft_ftoa(temp, 6);
    test = ft_ftoa(temp, 5);
    return (0);
}