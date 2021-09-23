#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct  s_format
{
    int     minus;
    int     zero;
    int     prec;
    int     width;
    int     star;
    int     hash;
    int     space;
    int     plus;
}               t_format;


int     ft_printf(const char *s, ...);
int     ft_handle_format(const char *input, va_list *ap, int *printed_char);
void    ft_handle_types(char type, va_list *ap, int *printed_char);
int     is_type(char c);

int	    ft_nbr_len(int n, int cnt);
void    print_char(va_list *ap, int *printed_char);
void    print_string(va_list *ap, int *printed_char);
void    print_int(va_list *ap, int *printed_char);
void    print_unsigned_int(va_list *ap, int *printed_char);
void    print_hex_upper_num(va_list *ap, int *printed_char);
void    print_hex_lower_num(va_list *ap, int *printed_char);
void    print_pointer(va_list *ap, int *printed_char);

void    convert_base(int n, int base_len, char *base, int *printed_char);
void    print_base(int n, int base_len, char *base, int *printed_char);
void    init_hex_upper_base(char *base);
void    init_hex_lower_base(char *base);

#endif