NAME = main.c
EXE = a.out
LIB = libft.a

all :
	gcc -Wall -Wextra -Werror $(NAME) $(LIB)
clean :
	rm -f $(EXE)
re : clean all
