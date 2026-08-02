cc=c++ -Wall -Wextra -Werror -std=c++98
NAME=RPN
files=main.cpp RPN.cpp
obj=$(files:.cpp=.o)

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)
%.o:%.cpp RPN.hpp
	$(cc) -c $<

clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)

re:fclean all
