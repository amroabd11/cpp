CC = c++
NAME = Bureaucrat
FLAGS=-Wall -Wextra -Werror
SRC=main.cpp Bureaucrat.cpp Form.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
%.o:%.cpp Bureaucrat.hpp Form.hpp
	$(CC) $(FLAGS) $< -c 
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re: fclean all
