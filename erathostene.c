#include <unistd.h>
#include <stdlib.h>

void erathostene(int a)
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
		k = i + 1;
		while (k < a - 1)
		{
			if (tab[k] % tab[i] == 0)
				tab[k] = 0;
			k++;	
		}
		i++;
	}
	i = 0;
	k = 1;
	while (i < a - 1)
	{
		if (tab[i] != 0)
			ft_printf("%d est le n°%d nombre  premier\n", tab[i], k++);
		i++;
	}
}

<<<<<<< HEAD
int main(void)
{
	erathostene(100);
=======
int main()
{
	erathostene(20);
>>>>>>> d4396eedc0e86bc5671c73df99818a6c2a2118c1
	return (0);
}
