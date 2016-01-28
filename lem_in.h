#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define CMD_END 1
# define CMD_START 2
# define CMD_UNKNOWN 3

# define COMMENT -1

# define MAP_LINE 0
# define ANT_LINE 10
# define HALL_LINE 20
# define TUBE_LINE 30
# define INVALID_LINE 40

typedef struct		s_hall
{
	char			*name;
	int				x;
	int				y;
}					t_hall;

typedef struct		s_tube
{
	char			*name1;
	char			*name2;
}					t_tube;

typedef struct		s_map
{
	char			**entry;
	char			state;
	int				ant_nb;
	t_tube			*tubes;
	t_hall			*halls;
	int				start;
	int				end;
	int				halls_size;
	int				tubes_size;
	int				next;
}					t_map;

void				lem_in_get_infos(t_map *map);
void				lem_in_print_error();
char				**lem_in_join_line(char **line, char ***read);
int					lem_in_str_is_all_num(char *str);
int					lem_in_is_hall_line(char *line);
int					lem_in_is_tube_line(char *line);
void				lem_in_print_entry(char **read);

#endif
