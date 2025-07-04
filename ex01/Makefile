CC = c++
CFLAGS = -Wall -Wextra -Werror  -std=c++98
NAME=phonebook
SRC=phonebook.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

NAME:$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp phonebook.h

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rif $(NAME)

re:fclean all	