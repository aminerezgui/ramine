#include <stdlib.h>
int chiffre(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	return (0);
}

int recolle(int a, int b)
{
	return (a * 10 + b);
}

int ft_atoi(char *str)
{
	int flag;
	int i;
	int rd;

	flag = 0;
	if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '+' && str[0] != '-' && str[0] != ' ')
		return (0);
	rd = chiffre(str[0]);
	if (str[0] == '-')
		flag++;
	i = 1;
	/*while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;*/
	while (str[i])
	{
		if (chiffre(str[i]) == 0 && str[i] != '0')
		{
			if (flag)
				return (-rd);
			return (rd);
		}
		rd = recolle(rd, chiffre(str[i]));
		i++;
	}
	if (flag)
		return (-rd);
	return (rd);
}

/*int main(void)
{
	ft_putnbr(ft_atoi("  22  "));
	ft_putchar('\n');
	ft_putnbr(atoi("  22  "));
	return (0);
}*/
