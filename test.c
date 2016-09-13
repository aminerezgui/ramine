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

void aff_var(char *str, ...)
{
	char *next;
	va_list ap;

	va_start(ap, str);
	next = str;
	while (next != 0)
	{
		ft_putstr(next);
		ft_putstr("\n");
		next = va_arg(ap, char*);
	}
	va_end(ap);
}

int main(void)
{
	aff_var("c'est", "pour", "toi", "abdu", 0);
}
