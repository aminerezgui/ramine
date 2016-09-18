int  ft_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])	
	{
		i++;
	}
	return (i);
}

char *rev(char *str)
{
	char	rev[ft_strlen(str)];
	int	i;
	int 	k;

	i = ft_strlen(str) - 1;
	k = 0;
	while (k < ft_strlen(str))
	{
		rev[k] = str[i];
		i--;
		k++;
	}
	i = 0;
	while (str[i])
	{
		str[i] = rev[i];
		i++;
	}
	return (str);
}
