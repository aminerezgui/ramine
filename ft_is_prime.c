#include "ft_list.h"
#include <stdlib.h>

int ft_is_prime(int nbr)
{
	int i;
	int cr;
	
	if (nbr < 2)
		return (0);
	i = 2;
	cr = i * i;
	while (cr <= nbr && cr > 0)
	{	
		if (nbr % i == 0)
			return (0);
		i++;
		cr = i * i;
	}
	return (1);
}

int *ft_combi(int nbr)
{
	int i;
	int k;
	
	int *tab;

	tab = (int*)malloc(sizeof(int) * 2);
	tab[0] = 1;
	tab[1] = nbr;
	if (ft_is_prime(nbr) || nbr < 2)
		return (tab);
	i = 2;
	while (i < nbr)
	{
		k = 2;
		while (k < nbr)
		{
			if (i * k == nbr)
			{
				tab[0] = i;
				tab[1] = k;
				return (tab);
			}
			k++;
		}
		i++;
	}
	return (tab);
}

t_list **ft_factorize(int n)
{
	t_list **first;
	t_list *t;
	int *nbr;
	int *tab;
	
	first = (t_list**)malloc(sizeof(t_list*));
	*first = 0;
	tab = ft_combi(n);
	ft_list_push_back(first, tab);
	ft_list_push_back(first, tab + 1);
	t = *first;
	while (t)
	{
		nbr = t->data;
		if (ft_is_prime(*nbr) == 0 && *nbr >= 2)
		{
			tab = ft_combi(*nbr);
			ft_list_push_back(first, tab);
			ft_list_push_back(first, tab + 1);
			*nbr = 0;
		}
		t = t->next;
	}
	return (first);
}
