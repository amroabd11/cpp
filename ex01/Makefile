CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME=phonebook
SRC=PhoneBook.cpp Contact.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAGS) $< -c

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all	
