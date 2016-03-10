/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_pathfinding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:02:22 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:08:10 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_init_nodes(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->graph_size)
	{
		if (map->graph[i].is_available == 1)
		{
			map->graph[i].weight = -1;
			map->graph[i].father = -1;
			map->graph[i].tag = 0;
		}
		if (map->graph[i].is_start == 1)
			map->graph[i].weight = 0;
		i++;
	}
}

int			lem_in_find_current(t_map *map)
{
	int		i;
	int		min;
	int		current;

	i = 0;
	min = -1;
	current = -1;
	while (i < map->graph_size)
	{
		if (map->graph[i].is_available && !map->graph[i].tag &&
				map->graph[i].weight > -1 && (map->graph[i].weight < min
					|| min == -1))
		{
			min = map->graph[i].weight;
			current = i;
		}
		i++;
	}
	return (current);
}

int			lem_in_create_path(t_map *map, int **path)
{
	int		i;
	int		len;
	int		*new;
	t_node	node;

	len = 1;
	node = map->graph[map->end];
	while (!node.is_start && len++)
		node = map->graph[node.father];
	if (!(new = (int *)malloc(sizeof(int) * len)))
		lem_in_print_error();
	i = len - 2;
	new[len - 1] = map->end;
	node = map->graph[map->end];
	while (i >= 0)
	{
		new[i--] = node.father;
		node = map->graph[node.father];
	}
	*path = new;
	return (len);
}

void		lem_in_son_weight(int cur, t_map *map)
{
	int		i;
	t_node	node;

	i = 0;
	node = map->graph[cur];
	while (i < node.links_size)
	{
		if (!map->graph[node.links[i]].tag && (map->graph[node.links[i]].weight
				== -1 || (node.weight + 1) < map->graph[node.links[i]].weight))
		{
			map->graph[node.links[i]].weight = node.weight + 1;
			map->graph[node.links[i]].father = cur;
		}
		i++;
	}
}

int			lem_in_pathfinding(t_map *map, int **path)
{
	int		i;
	int		len;
	int		cur;

	i = 0;
	len = 0;
	lem_in_init_nodes(map);
	while (1)
	{
		if ((cur = lem_in_find_current(map)) == -1)
			return (0);
		map->graph[cur].tag = 1;
		if (map->graph[cur].is_end)
		{
			len = lem_in_create_path(map, path);
			break ;
		}
		lem_in_son_weight(cur, map);
	}
	return (len);
}
