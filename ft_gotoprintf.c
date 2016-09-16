#include <unistd.h>
#include <stdarg.h>

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
	char *next;
	int next_int;
	long next_long;
	va_list ap;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			next = va_arg(ap, char*);
			ft_putstr(next);
			i+=2;
		}
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			next_int = va_arg(ap, int);
			ft_putnbr(next_int);
			i+=2;
		}
		if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'd')
		{
			next_long = va_arg(ap, long);
			ft_putnbr_long(next_long);
			i+=3;
		}
		if (str[i] == '\0')
			return ;
		write(1, str + i, 1);
		i++;
	}
	va_end(ap);
}
