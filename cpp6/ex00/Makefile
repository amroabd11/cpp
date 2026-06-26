CC=c++ -Wall -Wextra -Werror -std=c++98

files=main.cpp ScalarConverter.cpp
objects=$(files:.cpp=.o)
NAME=convert

all:$(NAME)

$(NAME):$(objects)
	$(CC) -o $(NAME) $(objects)
%.o:%.cpp ScalarConverter.hpp
	$(CC) -c  $<  
clean:
	rm -rf $(objects)
fclean:clean
	rm -rf $(NAME)
re: fclean all
