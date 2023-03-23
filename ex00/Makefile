NAME = btc
CPPFLAG = -Wall -Wextra -Werror -std=c++98 -g
R = '\033[91m'
G = '\033[92m'
SRCS =  BitcoinExchange.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)
all:$(NAME)
$(NAME) : $(OBJS)
	c++ $(CPPFLAG) $(OBJS) -o $(NAME)
	@echo $(G) "$(NAME) Created ! " $(NONE)
%.o : %.cpp BitcoinExchange.hpp
	c++ $(CPPFLAG) -c $< -o $@
clean:
	rm -f $(OBJS)
	@echo $(R) "deleted !" $(NONE)
fclean: clean
	rm -f $(NAME)
	@echo $(R) "$(NAME) has ben deleted !" $(NONE)
re : fclean all
.PHONY: all clean fclean re
