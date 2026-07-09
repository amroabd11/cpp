CC=c++ -Wall -Wextra -Werror -std=c++98

files=main123.cpp
objects=$(files:.cpp=.o)
NAME=iter

all:$(NAME)

$(NAME):$(objects)
	$(CC) -o $(NAME) $(objects)
%.o:%.cpp iter.hpp
	$(CC) -c  $<  
clean:
	rm -rf $(objects)
fclean:clean
	rm -rf $(NAME)
re: fclean all
