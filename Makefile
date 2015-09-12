NAME=test
SRC=*.c
TMP=*~

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC)

clean :
	rm -rf $(TMP)

fclean :
	rm -rf $(NAME)

re : fclean all