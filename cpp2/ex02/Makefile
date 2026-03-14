NAME=EX02
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Fixed.cpp
OBJS=$(SRC:.cpp=.o)
all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o:%.cpp Fixed.hpp
	$(CC) $(CFLAGS) $< -c
clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re:fclean all
