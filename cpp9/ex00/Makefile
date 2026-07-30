cc=c++ -Wall -Wextra -Werror -std=c++98
NAME=btc
files=main.cpp BitcoinExchange.cpp
obj=$(files:.cpp=.o)

all:$(NAME)

$(NAME):$(obj)
	$(cc) -o $(NAME) $(obj)
%.o:%.cpp BitcoinExchane.hpp
	$(cc) -c $<

clean:
	rm -rf $(obj)
fclean:clean
	rm -rf $(NAME)

re:fclean all
