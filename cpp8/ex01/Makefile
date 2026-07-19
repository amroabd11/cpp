CC=c++ -Wall -Wextra -Werror -std=c++98

files=main.cpp Span.cpp
objects=$(files:.cpp=.o)
NAME=Span

all:$(NAME)

$(NAME):$(objects)
	$(CC) -o $(NAME) $(objects)
%.o:%.cpp Span.hpp
	$(CC) -c  $<  
clean:
	rm -rf $(objects)
fclean:clean
	rm -rf $(NAME)
re: fclean all
