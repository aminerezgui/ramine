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
	char str[2] = "a";
	t_list **first;
	first = (t_list**)malloc(sizeof(t_list*));
	*first = 0;
	i = 0;

	while (str[i])
	{
		ft_list_push_back(first, str + i);
		i++;
	}
	ft_list_print(ft_list_copy(*first));
	return (0);
}
