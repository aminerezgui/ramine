NAME = main.c
EXE = a.out

all :
	gcc -Wall -Wextra -Werror $(NAME)
clean :
	rm -f $(EXE)
re : clean all
