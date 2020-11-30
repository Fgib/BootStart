##
## EPITECH PROJECT, 2020
## my_screensaver
## File description:
## Makefile
##

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system

OBJ	=			$(SRC:.c=.o)

SRC	=			cafard.c\
				runner.c\
				lego.c\
				rainbow.c\
				parallax.c

NAME	=		my_cafard\
				my_rainbow\
				my_runner\
				my_lego\
				my_parallax

all:	$(OBJ)
		gcc -o my_cafard cafard.o $(CSFMLFLAGS) -g3 -lm
		gcc -o my_runner runner.o $(CSFMLFLAGS) -g3 -lm
		gcc -o my_rainbow rainbow.o $(CSFMLFLAGS) -g3 -lm
		gcc -o my_lego lego.o $(CSFMLFLAGS) -g3 -lm
		gcc -o my_parallax parallax.o $(CSFMLFLAGS) -g3 -lm
		@ rm *.o

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *.vgcore*

re:	fclean all
