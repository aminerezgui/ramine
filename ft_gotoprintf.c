#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

void ft_putstr(char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void ft_putnbr_long(long nbr)
{
	if (nbr == -9223372036854775808)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putstr("-");
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48);
	else
	{
		ft_putnbr_long(nbr / 10);
		ft_putnbr_long(nbr % 10);
	}
}

void ft_printf(char *str, ...)
{
	int i;
	va_list ap;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		while (str[i] == '%')
		{
			if (str[i + 1] == 'c')
			{
				ft_putchar(va_arg(ap, int));
				i+=2;
			}
			if (str[i + 1] == 's')
			{
				ft_putstr(va_arg(ap, char*));
				i+=2;
			}
			else if (str[i + 1] == 'd')
			{
				ft_myputnbr(va_arg(ap, int));
				i+=2;
			}
			else if (str[i + 1] == 'l' && str[i + 2] == 'd')
			{
				ft_myputnbr(va_arg(ap,long));
				i+=3;
			}
			else if (str[i + 1] == 'x')
			{
				convert_base(va_arg(ap, long), 16);
				i+=2;
			}
			else
			{
				write(1, str + i, 1);
				i++;
			}
		}
		if (str[i] != '\0')
		{
			write(1, str + i, 1);
			i++;
		}
	}
	va_end(ap);
}

int main(void)
{
	printf("%x\n", 43);

	ft_printf("%x", 43);
}
