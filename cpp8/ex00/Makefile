cc=c++ -Wall -Wextra -Werror -std=c++98
files=main.cpp
obj = $(files:.cpp=.o)
NAME=easyfind

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)
%.o:%.cpp easyfind.hpp
	$(cc) -c $<
clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)
re: fclean all

