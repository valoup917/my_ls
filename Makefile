##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	src/main.c			\
		src/my_ls.c			\
		src/my_ls_l.c		\
		src/my_ls_l2.c		\
		src/my_ls_t.c		\
		src/my_ls_d.c		\
		src/my_ls_r.c		\
		src/my_ls_big_r.c	\
		src/redirection.c	\
		lib/my_putstr.c		\
		lib/my_strlen.c		\
		lib/my_putchar.c	\
		lib/my_put_nbr.c	\
		lib/my_strcmp.c		\
		lib/my_strlowcase.c	\
		lib/my_revstr.c		\
		lib/my_strcat.c		\
		lib/my_strtok.c		\

NAME	=	my_ls

all:
	gcc -o $(NAME) $(SRC) -Wall -Wextra

clean:
	clear
	rm -f *~
	rm -f \#*\#
	rm -f \#*

fclean: clean
	rm -f $(NAME)

re: fclean all
