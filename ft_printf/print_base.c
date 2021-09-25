#include "ft_printf.h"

void    convert_base(unsigned long int n, int base_len, char *base, int *printed_char)
{
    if (n == 0)
        return ;
    convert_base(n / base_len, base_len, base, printed_char);
    write(1, &base[n % base_len], 1);
    (*printed_char)++;
}

void    print_base(unsigned long int n, int base_len, char *base, int *printed_char)
{
    if (n == 0)
    {
        write(1, &base[0], 1);
        (*printed_char)++;
        return ;
    }
    convert_base(n, base_len, base, printed_char);
}