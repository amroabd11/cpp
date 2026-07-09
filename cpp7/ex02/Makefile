CC=c++ -Wall -Wextra -Werror -std=c++98

files=main.cpp
objects=$(files:.cpp=.o)
NAME=Array

all:$(NAME)

$(NAME):$(objects)
	$(CC) -o $(NAME) $(objects)
%.o:%.cpp Array.hpp
	$(CC) -c  $<  
clean:
	rm -rf $(objects)
fclean:clean
	rm -rf $(NAME)
re: fclean all
