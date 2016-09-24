#include <stdlib.h>
#include <stdio.h>

void eratosthene(int a)
{
	int k;
	int i;
	int *tab;

	tab = (int*)malloc(sizeof(int) * a - 1);
	i = 0;
	k = 2;
	while (i < a - 1)
	{
		tab[i] = k;
		i++;
		k++;
	}
	i = 0;
	while (i < a - 1)
	{
		if (tab[i] != 0)
		{
		k = i + 1;
		while (k < a - 1)
		{
			if (tab[k] % tab[i] == 0)
				tab[k] = 0;
			k++;	
		}
		}
		i++;
	}
	i = 0;
	k = 1;
	while (i < a - 1)
	{
		if (tab[i] != 0)
			ft_printf("%d\n", tab[i]);
		i++;
	}
}

int main()
{
	eratosthene(1000);
	return (0);
}
