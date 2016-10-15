#include <unistd.h>
#include "ft.h"

void ft_putnbr_spe(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48);
	if (nbr >= 10 && nbr <= 15)
		ft_putchar(nbr + 97 - 10);
}

void convert_base(long nbr, int base)
{
	if (nbr != 0)
		convert_base(nbr / base, base);
	if (nbr != 0)
		ft_putnbr_spe(nbr % base);
}
