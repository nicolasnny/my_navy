##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my first make file
##

CC = gcc

MAIN	=	tests/main.c

SRC     =	src/my_navy.c	\
		src/err_handling.c	\

CRFLAGS	=	--coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

NAME	=	my_navy

LDFLAGS =	-L./lib/my

LDLIBS	=	-lmy

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

LIBNAME	=	libmy.a

TEST_SRC	=	tests/unit_tests.c

TNAME	=	unit_tests

all:	lib $(NAME)

lib:
	$(MAKE) -C lib/my

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LDLIBS)

tests_run: lib
	$(CC) $(LDFLAGS) -o $(TNAME) $(TEST_SRC) $(OBJ) $(CRFLAGS) $(LDLIBS)
	./$(TNAME)

clean:
	$(MAKE) clean -C lib/my
	rm -f $(OBJ) *~  *.gcda *.gcno src/*.gc*

fclean:	clean
	rm -f $(NAME) $(TNAME) lib/my/$(LIBNAME)

debug:	CPPFLAGS += -g3
debug:	re

re:     fclean all

.PHONY: all lib tests_run clean fclean re debug
