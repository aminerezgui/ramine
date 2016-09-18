#include "ft.h"

void dectobin(int nbr)
{
	if (nbr != 0)
		dectobin(nbr / 2);
	ft_putnbr(nbr % 2);
}
