#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_map
{
	char			**entry;
}					t_map;

void				lem_in_get_infos(t_map *map);

#endif
