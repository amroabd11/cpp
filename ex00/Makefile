CC = c++
CFLAGS = -g -O0 -Wall -Wextra -Werror  -std=c++98 
NAME=megaphone
SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.cpp
	$(CC) $(CFLAGS) $< -c

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all	
