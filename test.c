#include <unistd.h>
#include <stdarg.h>

void aff(char c, ...)
{
	char next;
	va_list ap;

	va_start(ap, c);
	next = c;
	while (next != '\0')
	{
		write(1, &next, 1);
		next = va_arg(ap, int);
	}
	va_end(ap);
}

int main(void)
{
	aff('a', 'b', '\0');
}
