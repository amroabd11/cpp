cc=c++ -Wall -Wextra -Werror -std=c++98
NAME=PmergeMe
files=main.cpp PmergeMe.cpp
obj=$(files:.cpp=.o)

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)
%.o:%.cpp PmergeMe.hpp
	$(cc) -c $<

clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)

re:fclean all
