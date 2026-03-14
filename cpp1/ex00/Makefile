CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME=Wlakers
SRC=Zombie.cpp main.cpp randomChump.cpp newZombie.cpp 
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp Zombie.hpp


clean:
	rm -rif $(OBJ)
fclean:clean
	rm -rif $(NAME)
re:fclean all
