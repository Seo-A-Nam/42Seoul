#include "ft_printf.h"

int     is_type(char c)
{
    if (c == 'c' || c == 's' || c == 'p'
        || c == 'd' || c == 'i' || c == 'u'
        || c == 'x' || c == 'X' || c == '%')
        return (1);
    return (0);
}

void    ft_handle_types(char type, va_list *ap, int *printed_char)
{
    if (type == 'c')
        print_char(ap, printed_char);
    if (type == 's')
        print_string(ap, printed_char);
    if (type == 'p')
        print_pointer(ap, printed_char);
    if (type == 'd' || type == 'i')
        print_int(ap, printed_char);
    if (type == 'u')
        print_unsigned_int(ap, printed_char);
    if (type == 'x')
        print_hex_lower_num(ap, printed_char);
    if (type == 'X')
        print_hex_upper_num(ap, printed_char);
    if (type == '%')
        print_percent(ap, printed_char);
}

int     ft_handle_format(const char *input, va_list *ap, int *count)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] == '%' && is_type(input[i + 1]))
        {
            ft_handle_types(input[i + 1], ap, count);
            i += 2;
        }
        else
        {
            write(1, &input[i], 1);
            i++;
            (*count)++;
        }
    }
    return (0);
}

int     ft_printf(const char *s, ...)
{
    va_list     ap;
    const char  *input;
    int         printed_char;

    printed_char = 0;
    input = ft_strdup(s);
    va_start(ap, s);
    ft_handle_format(input, &ap, &printed_char);
    va_end(ap);
    free((char *)input);
    return (printed_char);
}