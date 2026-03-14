CC=c++
NAME=Fix
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=Fixed.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Fixed.hpp
	$(CC) $(CFLAGS) $< -c
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re: fclean all
