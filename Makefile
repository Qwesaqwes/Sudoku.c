NAME=test
SRC=*.c
TMP=*~

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean :
	rm -rf $(TMP)

fclean : clean
	rm -rf $(NAME)

re : fclean all