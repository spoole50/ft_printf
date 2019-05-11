#include <stdio.h>
#include <stdarg.h>

void    test_va(int ac, ...)
{
    va_list test;
    va_start(test, ac);
    void *p_test = va_arg(test, void*);
    void *p_test2 = va_arg(test, void*);
    va_end(test);
    printf("%s + %d\n", (char*)p_test, (int)p_test2);
}

int main(void)
{
    test_va(2, "This is a long tesssssssssstttttttdjklhfioewhfiowjofheowjofijweoeipfr8ue9purew8jufre8whf8jufuj[ioewjhfiowjkejr2 90uir92ir   jwPjeti0tewut90ewjrt90  3iru9   fe9w0jfifj", 6);
    return (0);
}