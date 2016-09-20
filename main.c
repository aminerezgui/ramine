#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

	begin_list_copy =(t_list*)malloc(sizeof(t_list));
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
	char *str;

	if (begin_list == 0)
		return ;
	t = begin_list;
	while (t->next)
	{
		str = t->data;
		write(1, str, 1);
		t = t->next;
	}
	str = t->data;
	write(1, str, 1);
}

t_list *ft_list_at(t_list *begin_list, int n)
{
	if ( n < 0)
		return (0);
	if (n == 0)
		return (begin_list);
	return ft_list_at(begin_list->next, n - 1);
}

int ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	return 1 + ft_list_size(begin_list->next);
}

t_list *read_to_list(int fd)
{
	int nb;
	char c;
	char *p;
	t_list *first;

	first = (t_list*)malloc(sizeof(t_list));
	first = 0;
	while (1)
	{
		nb = read(fd, &c, 1);
		if (nb == 0)
			break ;
		p = (char*)malloc(sizeof(char));
		*p = c;
		ft_list_push_back(&first, p);
	}
	return (first);
}

char *list_to_string(t_list *begin_list)
{
	t_list *t;
	char *str;
	int i;
	char *c;

	t = begin_list;
	i = 0;
	str = (char*)malloc(sizeof(char) * ft_list_size(begin_list) + 1);
	
	while (i < ft_list_size(begin_list))
	{
		c = t->data;
		str[i] = *c;
		t = t->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main(void)
{
	ft_putstr(list_to_string(read_to_list(0)));
}
