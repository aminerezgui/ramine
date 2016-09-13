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

t_list *ft_list_copy(t_list *begin_list_ref)
{
	t_list *t;
	t_list *r;
	t_list *begin_list_copy;
	if (begin_list_ref == 0)
	{
		begin_list_copy = 0;
		return (0);
	}
	t = begin_list_ref;
	r = begin_list_copy;
	r = ft_creat_elem(t->data);
	t = t->next;
	while (t)
	{
		r->next = ft_creat_elem(t->data);
		t = t->next;
		r = r->next;
	}
	return (begin_list_copy);
}

void ft_list_print(t_list *begin_list)
{
	t_list *t;

	if (begin_list == 0)
		return ;
	t = begin_list;
	while (t->next)
	{
		printf("%s\n", t->data);
		t = t->next;
	}
	printf("%s\n", t->data);	
}

t_list *ft_list_at(t_list *begin_list, int n)
{
	if ( n < 0)
		return (0);
	if (n == 0)
		return (begin_list);
	return ft_list_at(begin_list->next, n - 1);
}
int main(int ac, char **av)
{
	int i;
	t_list **first;
	first = (t_list**)malloc(sizeof(t_list*));
	*first = 0;
	i = ac - ac;

	while (av[i])
	{
		ft_list_push_back(first, av[i]);
		i++;
	}
	ft_list_print(*first);
	printf("%s", (ft_list_at(*first, 2))->data);
	return (0);
}
