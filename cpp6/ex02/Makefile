cc=c++ -Wall -Wextra -Werror -std=c++98
files=main.cpp Base.cpp
obj=$(files:.cpp=.o)
NAME=Base

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)
%.o:%.cpp Base.hpp functions.hpp
	$(cc) -c $<
clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)
re:fclean all
