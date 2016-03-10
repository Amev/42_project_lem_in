/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_graph_constructor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:01:30 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:07:19 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_join_nodes(t_map *map, t_hall hall)
{
	int		i;
	t_node	node;
	t_node	*new;

	i = 0;
	node.ant = -1;
	node.hall = hall;
	node.links = NULL;
	node.is_end = 0;
	node.is_start = 0;
	node.links_size = 0;
	node.is_available = 1;
	if (!(new = (t_node *)malloc(sizeof(t_node) * (map->graph_size + 1))))
		lem_in_print_error();
	new[map->graph_size] = node;
	while (i++ < map->graph_size)
		new[i - 1] = map->graph[i - 1];
	if (map->graph)
		free(map->graph);
	map->graph_size++;
	map->graph = new;
}

int			lem_has_link(t_node node, int index)
{
	int		i;

	i = 0;
	while (i < node.links_size)
		if (node.links[i++] == index)
			return (1);
	return (0);
}

void		lem_in_link_node(t_node *node, int index)
{
	int		i;
	int		*new;

	i = 0;
	if (!(new = (int *)malloc(sizeof(int) * (node->links_size + 1))))
		lem_in_print_error();
	while (i++ < node->links_size)
		new[i - 1] = node->links[i - 1];
	new[node->links_size] = index;
	if (node->links)
		free(node->links);
	node->links = new;
	node->links_size++;
}

void		lem_in_link_nodes(t_tube tube, t_map *map)
{
	if (!lem_has_link(map->graph[tube.index1], tube.index2))
		lem_in_link_node(&(map->graph[tube.index1]), tube.index2);
	if (!lem_has_link(map->graph[tube.index2], tube.index1))
		lem_in_link_node(&(map->graph[tube.index2]), tube.index1);
}

void		lem_in_graph_constructor(t_map *map)
{
	int		i;

	i = 0;
	lem_in_map_names(map);
	while (i < map->halls_size)
		lem_in_join_nodes(map, map->halls[i++]);
	map->graph[map->end].is_end = 1;
	map->graph[map->start].is_start = 1;
	i = 0;
	while (i < map->tubes_size)
		lem_in_link_nodes(map->tubes[i++], map);
}
