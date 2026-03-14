CC=g++
CFLAGS=-Wall -Wextra  -Werror -g -std=c++98
NAME=HARL
SRC=main.cpp Harl.cpp
OBJ=$(SRC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Harl.hpp

clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean all

