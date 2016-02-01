#include "lem_in_functions.h"

int			lem_in_map_names(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->tubes_size)
	{
		j = 0;
		map->tubes[i].index1 = -1;
		map->tubes[i].index2 = -1;
		while (j++ < map->halls_size)
		{
			if (ft_strcmp(map->tubes[i].name1, map->halls[j - 1].name) == 0)
				map->tubes[i].index1 = j - 1;
			if (ft_strcmp(map->tubes[i].name2, map->halls[j - 1].name) == 0)
				map->tubes[i].index2 = j - 1;
		}
		if (map->tubes[i].index1 == -1 || map->tubes[i].index2 == -1)
			lem_in_print_error();
		i++;
	}
	return (1);
}
