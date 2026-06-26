cc=c++ -Wall -Wextra -Werror -std=c++98

files=main.cpp Serializer.cpp
obj=$(files:.cpp=.o)
NAME = serializer

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)

%.o:%.cpp Serializer.hpp
	$(cc) -c  $< 

clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)
re:fclean all
