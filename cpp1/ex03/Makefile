
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
NAME=H_weapon
SRC=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp HumanA.hpp HumanB.hpp Weapon.hpp

clean:
	rm -rf $(OBJ)
fclean :clean
	rm -rf $(NAME)
re:fclean all

