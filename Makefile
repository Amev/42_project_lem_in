# **************************************************************************** #
#                                                                              #
#           CIBLES PRIORITAIRES POUR LES REGLES SANS DEPENDANCES               #
#                                                                              #
# **************************************************************************** #

.PHONY:			all lib clean fclean re


# **************************************************************************** #
#                                                                              #
#  DESACTIVATION DES REGLES IMPLICITES POUR EVITER LA COMPILATION AUTOMATIQUE  #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:


# **************************************************************************** #
#                                                                              #
#                                 VARIABLES                                    #
#                                                                              #
# **************************************************************************** #

NAME =			lem-in

INC =			lem_in.h
SRC =			lem_in_main.c lem_in_get_infos.c lem_in_error.c lem_in_tools.c

BINAIRE =		$(SRC:.c=.o)
TMP =			$(INC:.h=.h.gch)

CC =			gcc
CFLAGS =		-g -O3 -Werror -Wextra -Wall
LDFLAGS =		-lm -L libft/ -lft
INCLUDEDIR =	libft/includes/


# **************************************************************************** #
#                                                                              #
#                                  REGLES                                      #
#                                                                              #
# **************************************************************************** #

all: lib $(NAME)
				@:

$(NAME): $(BINAIRE) $(INC)
				$(CC) -o $(NAME) $(BINAIRE) $(LDFLAGS)

%.o: %.c
				$(CC) $(CFLAGS) -I $(INCLUDEDIR) -c $^ -o $@

lib:
				@git submodule --quiet init
				@git submodule --quiet update
				@make -s -C libft/

clean:
				@rm -f $(BINAIRE)

fclean: clean
				@rm -f $(NAME)

re: fclean all
