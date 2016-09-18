#include <stdlib.h>

char *zero(char *str)
{
	str =(char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void ft_myputnbr(long a)
{
	long r;
	int compt;
	char *str;
	
	if (a == 0)
	{
		ft_putstr(zero(str));
		return ;
	}
	compt = 0;
	if (a < 0)
		ft_putstr("-");
	r = a;
	while (r != 0)
	{
		r = r / 10;
		compt++;
	}
	str =(char*)malloc(sizeof(char) * compt + 1);
	r = a;
	str[compt] = '\0';
	while (r != 0)
	{
		if (r < 0)
			str[compt - 1] = -(r % 10) + 48;
		else
			str[compt - 1] = r % 10 + 48;
		r = r / 10;
		compt--;
	}
	ft_putstr(str);
	free(str);
}

int main(void)
{
	ft_myputnbr(1212);
	return (0);
}
