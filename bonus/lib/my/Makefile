##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Write a Makefile that compiles your libmy.
## It should perform the following actions:
##

SRC	=	my_showmem.c	\
		my_str_isalpha.c	\
		my_strncat.c	\
		my_isneg.c	\
		my_showstr.c    \
		my_str_islower.c	\
		my_strncmp.c	\
		my_is_prime.c	\
		my_sort_int_array.c	\
		my_str_isnum.c	\
		my_strncpy.c	\
		my_compute_power_rec.c	\
		my_putchar.c	\
		my_strcapitalize.c	\
		my_str_isprintable.c	\
		my_strstr.c	\
		my_compute_square_root.c\
		my_put_nbr.c	\
		my_put_unbr.c	\
		my_strcat.c	\
		my_str_isupper.c	\
		my_strupcase.c	\
		my_find_prime_sup.c	\
		my_putstr.c	\
		my_strcmp.c	\
		my_strlen.c 	\
		my_swap.c	\
		my_getnbr.c	\
		my_revstr.c	\
		my_strcpy.c	\
		my_strlowcase.c	\
		my_strstrlen.c	\
		my_putchar_err.c	\
		my_putstr_err.c	\
		my_str_to_line_array.c	\
		my_nb_to_str.c	\
		my_open_file.c	\
		my_getnbr_size.c	\
		mini_printf.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS	=

CFLAGS	=	-Wall -Wextra

HFILE	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

copy:
	cp libmy.a  ../libmy.a
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

debug:	CPPFLAGS += -g3
debug:	re

re:	fclean all

.PHONY: all copy clean fclean debug re
