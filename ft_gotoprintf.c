#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

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
				convert_base(va_arg(ap, long), 16, 97);
				i+=2;
			}
			else if (str[i + 1] == 'X')
			{
				convert_base(va_arg(ap, long), 16, 65);
				i+=2;
			}
			else if (str[i + 1] == 'b')
			{
				convert_base(va_arg(ap, long), 2, 0);
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
	printf("le nombre %d en base hexadecimale est : %X et en base binaire c'est : %b", 2016, 2016, 2016);
	printf("\n\n");
	ft_printf("le nombre %d en base hexadecimale est : %X et en base binaire c'est : %b", 2016, 2016, 2016);
	return (0);
}
