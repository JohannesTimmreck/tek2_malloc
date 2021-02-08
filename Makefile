##
## EPITECH PROJECT, 2019
## PSU_2019_malloc
## File description:
## Makefile
##

SRC	=	malloc.c	\
		free.c  \
		calloc.c	\
		realloc.c	\
		reallocarray.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CC  =   gcc

CFLAGS +=	-g -W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
		$(CC) -shared -fPIC -o $(NAME)  $(SRC)

test: $(CC) main.c -o test

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
