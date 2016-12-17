#include "ft_lib.h"

void initialize(int *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[i] = 0;
		i++;
	}
}

void char_to_tab(char *str, int *tab)
{
	int i;
	int k;

	initialize(tab);
	k = 0;
	i = 0;

	if (str[i] >= '0' && str[i] <= '9')
	{
		tab[0] = ft_atoi(str);
		k = 1;
		i = 1;
	}
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') &&
		!(str[i - 1] >= '0' && str[i - 1] <= '9'))
		{
			tab[k] = ft_atoi(str + i);
			k++;
		}
		i++;
	}
}


void fill_in_tabs(int ac, char **av)
{
	int i;
	int k;
	int s[4];
	int **tab1;
	int **tab2;

	char_to_tab(av[1], s);
	tab1 = ft_creat_tab(s[0], s[1]);
	tab2 = ft_creat_tab(s[2], s[3]);
	if (ac != s[0] + s[2] + 2 || s[1] != s[2])
		return ft_putstr("Oups la saisie est mauvaise\n");
	i = 2;
	k = 0;
	while (k < s[0])
	{
		char_to_tab(av[i], tab1[k]);
		k++;
		i++;
	}
	k = 0;
	while (k < s[2])
	{
		char_to_tab(av[i], tab2[k]);
		i++;
		k++;
	}
	ft_print_tab(tab1, s[0], s[1]);
	ft_putstr("\nx\n\n");
	ft_print_tab(tab2, s[2], s[3]);
	ft_putstr("\n=\n\n");
	ft_print_tab(ft_mix_mat(tab1, tab2, s[0], s[2], s[3]), s[0], s[3]);
}

void fill_in_tabs_pow(int ac, char **av)
{
	int i;
	int k;
	int s[3];
	int **tab1;
	int **dep;

	char_to_tab(av[1], s);
	tab1 = ft_creat_tab(s[0], s[1]);
	dep = ft_creat_tab(s[0], s[1]);
	if (s[0] != s[1] || ac != s[0] + 2)
		return ft_putstr("Oups la saisie est mauvaise\n");
	i = 2;
	k = 0;
	while (k < s[0])
	{
		char_to_tab(av[i], tab1[k]);
		char_to_tab(av[i], dep[k]);
		k++;
		i++;
	}
	ft_print_tab(tab1, s[0], s[1]);
	k = 1;
	while (k < s[2])
	{
		tab1 = ft_mix_mat(tab1, dep, s[0], s[1], s[1]);
		k++;	
	}
	ft_putstr("\na la puissance : ");
	ft_myputnbr(s[2]);	
	ft_putstr("\n\n");
	ft_print_tab(tab1, s[0], s[1]);

}

int main(int ac, char **av)
{
	if (ac > 2)
		fill_in_tabs_pow(ac, av);
	return (0);
}
