#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *ft_creat_elem(void *data)
{
	t_list *elem;

	elem =(t_list*)malloc(sizeof(t_list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *t;
	t_list *elem;

	elem = ft_creat_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = elem;
		return ;
	}
	t = *begin_list;
	while (t->next)
	{
		t = t->next;	
	}
	t->next = elem;

}

void ft_list_print(t_list *begin_list)
{
	t_list *t;

	if (begin_list == 0)
		return ;
	t = begin_list;
	while (t->next)
	{
		write(1, t->data, 1);
		//printf("%s", t->data);
		t = t->next;
	}
	//printf("%s", t->data);	
	write(1, t->data, 1);
}


int main(void)
{
	int i;
	char str[10] = "aminerez";
	t_list **first;
	first = (t_list**)malloc(sizeof(t_list*));
	*first = 0;
	i = 0;

	while (str[i])
	{
		ft_list_push_back(first, str + i);
		i++;
	}
	ft_list_print(*first);
	return (0);
}
