#include "libftprintf.h"

int	ft_nbr_len(int n, int cnt)
{
	if (n == 0 && cnt != 0)
		return (cnt);
	return (ft_nbr_len(n / 10, cnt + 1));
}

void    print_char(va_list *ap, int *printed_char)
{
    char    c;

    c = va_arg(*ap, int);
    write(1, &c, 1);
    (*printed_char)++;
}

void    print_string(va_list *ap, int *printed_char)
{
    char    *s;
    int     len;

    s = va_arg(*ap, char *);
    len = ft_strlen(s);
    write(1, s, len);
    (*printed_char) += len;
}

void    print_int(va_list *ap, int *printed_char)
{
    int     n;

    n = va_arg(*ap, int);
    ft_putnbr_fd(n, 1);
    (*printed_char) += ft_nbr_len(n, 0);
}

void    print_unsigned_int(va_list *ap, int *printed_char)
{
    unsigned int n;

    n = va_arg(*ap, unsigned int);
    ft_putnbr_fd(n, 1);
    (*printed_char) += ft_nbr_len(n, 0);
}
