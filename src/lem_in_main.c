#include "lem_in.h"

void		lem_in_init_map(t_map *map)
{
	map->next = 0;
	map->end = -1;
	map->start = -1;
	map->graph = NULL;
	map->halls = NULL;
	map->tubes = NULL;
	map->halls_size = 0;
	map->tubes_size = 0;
	map->graph_size = 0;
	map->state = ANT_LINE;
}

int			main(void)
{
	t_map	map;

	lem_in_init_map(&map);
	lem_in_get_infos(&map);
	lem_in_graph_constructor(&map);
	lem_in_print_t_map(map);
	return (0);
}
