#include "ft_lib.h"


void ft_myputdec(double f)
{
	ft_myputnbr((long)f);
	ft_putchar('.');
	ft_myputnbr(((long)(f * 1000000)) % 1000000);
}
