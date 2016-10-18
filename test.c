#include <unistd.h>
#include <stdarg.h>

va_list aff_derch(va_list ap)
{
	char *next;

	next = va_arg(ap, char*);
	while (next != 0)
	{
		ft_putstr(next);
		ft_putstr("\n");
		next = va_arg(ap, char*);
	}
	return (ap);
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
	next = va_arg(aff_derch(ap), char*);
	ft_putstr(next);
	va_end(ap);
}

int main(void)
{
	aff_var("c'est", "pour", "toi", "abdu", 0, "et", "rebolote", 0, "FINISH");
	return (0);
}
