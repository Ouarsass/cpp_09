NAME = ReversePolishNotation
CPPFLAG = -Wall -Wextra -Werror -std=c++98
SRCS =  RPN.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)
all:$(NAME)
$(NAME) : $(OBJS)
	c++ $(CPPFLAG) $(OBJS) -o $(NAME)
%.o : %.cpp Fixed.hpp
	c++ $(CPPFLAG) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all