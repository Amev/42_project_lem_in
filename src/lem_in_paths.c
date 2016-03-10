/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:02:47 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 16:41:13 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (len < map->shortest_len || map->shortest_len == -1)
	{
		map->shortest_len = len;
		map->shortest_path = map->paths_size;
	}
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

void		lem_in_calc_extra(t_map *map)
{
	int		i;

	i = 0;
	while (i++ < map->paths_size)
		map->paths[i - 1].extra = map->paths[i - 1].len - map->shortest_len;
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
		if (len == 2)
			break ;
	}
	lem_in_calc_extra(map);
	if (map->paths_size <= 0)
		lem_in_print_error();
}
