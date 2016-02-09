#include "lem_in.h"

t_ant		lem_in_new_ant(int name, int node)
{
	t_ant	new;

	new.name = name;
	new.node = node;
	return (new);
}

void		lem_in_init_ants(t_map *map)
{
	int		i;

	i = 0;
	map->ants_start = map->ant_nb;
	if (!(map->ants = (t_ant *)malloc(sizeof(t_ant) * map->ant_nb)))
		lem_in_print_error();
	while (i++ < map->ant_nb)
		map->ants[i - 1] = lem_in_new_ant(i, map->start);
}

int			lem_in_win_test(t_map *map)
{
	int		i;

	i = map->ant_nb;
	ft_printf("\n");
	while (i-- > 0)
		if (map->ants[i].node != map->end)
			return (0);
	return (1);
}

int			lem_in_move_path_ants(t_map *map, int i, char c)
{
	int		j;
	int		ant;
	int		node;

	node = -1;
	j = map->paths[i].len - 1;
	while (j-- > 0)
	{
		if ((ant = map->graph[map->paths[i].path[j]].ant) != -1)
		{
			node = map->paths[i].path[j + 1];
			map->ants[ant].node = node;
			map->graph[node].ant = ant;
			map->graph[map->paths[i].path[j]].ant = -1;
			ft_printf("%cL%d-%s", c, map->ants[ant].name,
					map->graph[node].hall.name);
			c = ' ';
		}
	}
	return (node);
}

void		lem_in_ants_moves(t_map *map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	lem_in_init_ants(map);
	while (!lem_in_win_test(map) && !(i = 0))
	{
		c = 0;
		while (i++ < map->paths_size)
		{
			if (lem_in_move_path_ants(map, i - 1, c) != -1)
				c = ' ';
			if (map->ants_start > (map->paths[i - 1].extra + 1) ||
					(map->ants_start && map->paths[i - 1].extra == 0))
			{
				map->ants[j].node = map->paths[i - 1].path[1];
				map->graph[map->paths[i - 1].path[1]].ant = j;
				ft_printf("%cL%d-%s", c, map->ants[j++].name,
					map->graph[map->paths[i - 1].path[1]].hall.name);
				c = ' ';
				map->ants_start--;
			}
		}
	}
}
