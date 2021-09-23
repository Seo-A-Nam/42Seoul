#include "libftprintf.h"

void    print_pointer(va_list *ap, int *printed_char)
{
    (void)*ap;
    (*printed_char)++;
}