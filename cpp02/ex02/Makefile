NAME =	 Fixed

SRC =	main.cpp\
		Fixed.cpp\


OBJS = ${SRC:.cpp=.o}



 CC = clang++ -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		
		$(CC) $(SRC) -o  $(NAME)  -Wall -Wextra -Werror

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all