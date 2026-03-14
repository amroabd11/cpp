CC=c++  
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp
OBJ =$(SRC:.cpp=.o)
NAME=Brain
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re : fclean all
