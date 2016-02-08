#include "lem_in.h"

void		lem_in_join_paths(t_map *map, int **path, int len)
{
	int		i;
	t_path	*new;
	t_path	new_path;

	i = 0;
	new_path.path = *path;
	new_path.len = len;
	if (!(new = (t_path *)malloc(sizeof(t_path) * (map->paths_size + 1))))
		lem_in_print_error();
	while (i++ < map->paths_size)
		new[i - 1] = map->paths[i - 1];
	new[map->paths_size] = new_path;
	if (map->paths)
		free(map->paths);
	map->paths_size++;
	map->paths = new;
}

void		lem_in_unavailable_halls(t_map *map, int *path, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!map->graph[path[i]].is_start && !map->graph[path[i]].is_end)
			map->graph[path[i]].is_available = 0;
		i++;
	}
}

void		lem_in_paths(t_map *map)
{
	int		len;
	int		*path;

	path = NULL;
	while ((len = lem_in_pathfinding(map, &path)))
	{
		lem_in_join_paths(map, &path, len);
		lem_in_unavailable_halls(map, path, len);
		path = NULL;
	}
}
