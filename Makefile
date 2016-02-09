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

INC =			src/lem_in.h
SRC =			src/lem_in_main.c src/lem_in_get_infos.c src/lem_in_paths.c \
				src/lem_in_graph_constructor.c src/lem_in_pathfinding.c \
				src/lem_in_ants_moves.c
FUNC =			functions/lem_in_is_hall_line.c functions/lem_in_is_tube_line.c \
				functions/lem_in_join_line.c functions/lem_in_print_entry.c \
				functions/lem_in_print_error.c functions/lem_in_str_is_all_num.c \
				functions/lem_in_map_names.c

BINAIRE =		$(SRC:.c=.o) $(FUNC:.c=.o)
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
