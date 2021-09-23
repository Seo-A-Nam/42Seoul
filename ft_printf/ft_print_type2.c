#include "libftprintf.h"

void    init_hex_upper_base(char *base)
{
    char    c;
    int     i;

    i = 0;
    c = '0';
    while (i < 10)
    {
        base[i] = c++;
        i++;
    }
    c = 'A';
    while (i < 16)
    {
        base[i] = c++;
        i++;
    }
}

void    init_hex_lower_base(char *base)
{
    char    c;
    int     i;

    i = 0;
    c = '0';
    while (i < 10)
    {
        base[i] = c++;
        i++;
    }
    c = 'a';
    while (i < 16)
    {
        base[i] = c++;
        i++;
    }
}

void    print_hex_upper_num(va_list *ap, int *printed_char)
{
    char    base[16];
    int     n;

    init_hex_upper_base(base);
    n = va_arg(*ap, int);
    print_base(n, 16, base, printed_char);
}

void    print_hex_lower_num(va_list *ap, int *printed_char)
{
    char    base[16];
    int     n;

    init_hex_lower_base(base);
    n = va_arg(*ap, int);
    print_base(n, 16, base, printed_char);
}