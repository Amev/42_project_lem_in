/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:01:37 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:01:38 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_init_map(t_map *map)
{
	map->next = 0;
	map->end = -1;
	map->start = -1;
	map->graph = NULL;
	map->halls = NULL;
	map->tubes = NULL;
	map->paths = NULL;
	map->halls_size = 0;
	map->tubes_size = 0;
	map->graph_size = 0;
	map->paths_size = 0;
	map->state = ANT_LINE;
	map->shortest_len = -1;
	map->shortest_path = -1;
}

void		lem_in_check_map(t_map *map)
{
	if (map->end < 0 || map->start < 0 || map->halls_size <= 0 ||
			map->tubes_size <= 0)
		lem_in_print_error();
}

int			main(void)
{
	t_map	map;

	lem_in_init_map(&map);
	lem_in_get_infos(&map);
	lem_in_check_map(&map);
	lem_in_graph_constructor(&map);
	lem_in_paths(&map);
	lem_in_print_entry(map.entry);
	lem_in_ants_moves(&map);
	return (0);
}
