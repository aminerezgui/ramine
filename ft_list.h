#ifndef FT_LIST_H
# define FT_LIST_H

struct s_list
{
	struct s_list *next;
	void *data;
};
typedef struct s_list t_list;

t_list *ft_creat_elem(void *data);
void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_copy(t_list *begin_list_ref);
void ft_list_print_char(t_list *begin_list);
t_list *ft_list_at(t_list *begin_list, int n);
int ft_list_size(t_list *begin_list);
void ft_list_free(t_list *first);
t_list *read_to_list(int fd);
char *list_to_string(t_list *begin_list);
void ft_list_print_int(t_list *first);
void ft_list_remove_if(t_list **first, int(*f)(void*));

#endif
