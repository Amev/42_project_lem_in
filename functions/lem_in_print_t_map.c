#include "lem_in_functions.h"

void		lem_in_print_t_hall(t_hall hall)
{
	ft_printf("name: {grn}%s{eoc} | x: {ylw}%d{eoc} | y: {ylw}%d{eoc}\n", hall.name, hall.x, hall.y);
}

void		lem_in_print_t_tube(t_tube tube)
{
	ft_printf("name1: {grn}%s{eoc} | name2: {grn}%s{eoc}\n", tube.name1, tube.name2);
}

void		lem_in_print_t_node(t_node node)
{
	int		i;

	i = 0;
	ft_printf("hall: ");
	lem_in_print_t_hall(node.hall);
	ft_printf("data: is_start = {ylw}%d{eoc} | is_end = {ylw}%d{eoc}\n", node.is_start, node.is_end);
	ft_printf("links:{ylw}");
	while (i < node.links_size)
		ft_printf(" %d", node.links[i++]);
	ft_printf("{eoc}\n");
}

void		lem_in_print_t_map(t_map map)
{
	int		i;

	i = 0;
	ft_printf("{red}### entry ###{eoc}\n");
	lem_in_print_entry(map.entry);
	ft_printf("\nant_nb: {ylw}%d{eoc} | start: {ylw}%d{eoc} | end: {ylw}%d{eoc}\n\n", map.ant_nb, map.start, map.end);
	ft_printf("{red}### halls ###{eoc}\n");
	while (i < map.halls_size)
		lem_in_print_t_hall(map.halls[i++]);
	i = 0;
	ft_printf("\n{red}### tubes ###{eoc}\n");
	while (i < map.tubes_size)
		lem_in_print_t_tube(map.tubes[i++]);
	i = 0;
	ft_printf("\n{red}### graph ###{eoc}\n");
	while (i < map.graph_size)
		lem_in_print_t_node(map.graph[i++]);
}
