##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## pong
##

SRC	=	pong.c			\

CC	=	gcc -o

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror  -I./include/ -lm

NAME	=	101pong

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\e[44;1m----------------THATS WORK !!!----------------\e[0m"

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
