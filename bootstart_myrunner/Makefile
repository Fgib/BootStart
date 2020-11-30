##
## EPITECH PROJECT, 2020
## my_screensaver
## File description:
## Makefile
##

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system

OBJ	=			$(SRC:.c=.o)

SRC	=			main.c\
				unframed.c

NAME	=		my_bootstart

all:	$(OBJ)
		gcc -o $(NAME) main.o $(CSFMLFLAGS) -g3 -lm
		gcc -o unframed unframed.o $(CSFMLFLAGS) -g3 -lm
		@ rm *.o

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *.vgcore*

re:	fclean all
