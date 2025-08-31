CC = c++
CFLAGS = -Wall -Wextra -Werror  -std=c++98
NAME = Bank
SRC=Account.cpp tests.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

NAME:$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Account.hpp

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rif $(NAME)

re:fclean all	