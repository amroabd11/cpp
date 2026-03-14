CC = c++
NAME = Bureaucrat0
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Bureaucrat.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Bureaucrat.hpp
	$(CC) $(FLAGS) $< -c 
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re: fclean all
