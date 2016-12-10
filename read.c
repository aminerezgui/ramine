
void char_to_tab(char *str, int *tab)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (str[i] != ' ')
	{
		tab[0] = atoi(str);
		k = 1;
		i = 1;
	}
	while (str[i])
	{
		if (str[i] != ' ' && str[i - 1] == ' ')
		{
			tab[k] = atoi(str + i);
			k++;
		}
		i++;
	}
}


void fill_in_tabs(char **av)
{
	int i;
	int k;
	int s[4];
	int **tab1;
	int **tab2;

	char_to_tab(av[1], s);
	tab1 = ft_creat_tab(s[0], s[1]);
	tab2 = ft_creat_tab(s[2], s[3]);
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
	ft_print_tab(ft_mix_mat(tab1, tab2, s[0], s[1], s[3]), s[0], s[3]);
}


int main(int ac, char **av)
{
	fill_in_tabs(av);
	return (0);
}
