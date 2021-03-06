#include <stdlib.h>
#include "ft_lib.h"

int **ft_creat_tab(int line, int column)
{
	int **tab;
	int i;

	if (line == 0 || column == 0)
		return (0);
	tab = (int**)malloc(sizeof(int*) * line);
	i = 0;
	while (i < line)
	{
		tab[i] = (int*)malloc(sizeof(int) * column);
		i++;
	}
	return (tab);
}

void ft_print_tab(int **tab, int line, int column)
{
	int i;
	int j;

	if (tab == 0)
		return ;
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < column)
		{
			ft_myputnbr(tab[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int *extract_co(int **tab, int line, int num_co)
{
	int *extra;
	int i;

	extra = (int*)malloc(sizeof(int)* line);
	i = 0;
	while (i < line)
	{
		extra[i] = tab[i][num_co];
		i++;
	}
	return (extra);
}

int mix_lc(int *l, int *c, int p)
{
	int i;
	int result;

	i = 0;
	result = 0;
	
	while (i < p)
	{
		result = result + l[i] * c[i];
		i++;
	}
	return (result);
}

int **ft_mix_mat(int **tab1, int **tab2, int n, int p, int q)
{
	int **tab;
	int i;
	int j;
	int *extra;

	if (tab1 == 0 || tab2 == 0)
		return (0);
	tab = ft_creat_tab(n, q);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < q)
		{
			extra = extract_co(tab2, p, j);
			tab[i][j] = mix_lc(tab1[i], extra, p);
			free(extra);
			j++;
		}
		i++;
	}
	return (tab);
}
