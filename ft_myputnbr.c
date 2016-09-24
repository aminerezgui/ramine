#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void ft_myputnbr(long a)
{	
	char *c;
	t_list **first;

	first = (t_list**)malloc(sizeof(t_list*));
	*first = 0;
	if (a < 0)
		write(1, "-", 1);
	while (a != 0)
	{
		c = (char*)malloc(sizeof(char));
		if (a > 0)
			*c = a % 10 + 48;
		else
			*c = -(a % 10) + 48;
		ft_list_push_front(first, c);
		a = a / 10;
	}
	if (!*first)
		return write(1, "0", 1);
	ft_list_print(*first);
	free(first);
}

int main(void)
{
	ft_myputnbr(-1324);
	return (0);
}
