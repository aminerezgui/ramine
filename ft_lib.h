#ifndef FT_LIB_H
# define FT_LIB_H

int ft_putchar(char c);
void ft_putstr(char *str);
void ft_myputnbr(long nbr);
void ft_myputdec(double f);
void convert_base(long nbr, int base, int maj);

char *rev(char *str);
void ft_putnbr(int nbr);
int ft_atoi(char *str);

int **ft_creat_tab(int line, int column);
void ft_print_tab(int **tab, int line, int column);
int **ft_mix_mat(int **tab1, int **tab2, int n, int p, int q);

#endif
