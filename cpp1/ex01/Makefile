CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC=Zombie.cpp main.cpp zombieHorde.cpp 
OBJ=$(SRC:.cpp=.o)
NAME=Horde
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Zombie.hpp

clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean all

