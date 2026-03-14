CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC= main.cpp
OBJ= $(SRC:.cpp=.o)
NAME=SedLosers

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)  $(OBJ) 
%.cpp:%.o

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re:fclean all
