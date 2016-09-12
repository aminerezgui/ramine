NAME = main.c
EXE = a.out

all :
	gcc -Wall -Wextra -Werror $(NAME)
exe : 
	./$(EXE)
clean :
	rm -f $(EXE)
re : clean all exe
