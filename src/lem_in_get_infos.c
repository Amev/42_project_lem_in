/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_get_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:01:18 by vame              #+#    #+#             */
/*   Updated: 2016/03/15 10:19:45 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	lem_in_line_type(char *line)
{
	if (line[0] && line[0] == '#' && line[1] && line[1] == '#')
	{
		if (ft_strcmp("##start", line) == 0)
			return (CMD_START);
		else if (ft_strcmp("##end", line) == 0)
			return (CMD_END);
		return (CMD_UNKNOWN);
	}
	else if (line[0] && line[0] == '#')
		return (COMMENT);
	else if (lem_in_str_is_all_num(line))
		return (ANT_LINE);
	else if (lem_in_is_hall_line(line))
		return (HALL_LINE);
	else if (lem_in_is_tube_line(line))
		return (TUBE_LINE);
	return (INVALID_LINE);
}

static void	lem_in_add_hall_line(char *line, t_map *map)
{
	int		i;
	char	**split;
	t_hall	new_hall;
	t_hall	*new_halls;

	i = 0;
	if (!(split = ft_strsplit(line, ' ')))
		lem_in_print_error();
	if (!(new_hall.name = ft_strdup(split[0])))
		lem_in_print_error();
	new_hall.x = ft_atoi(split[1]);
	new_hall.y = ft_atoi(split[2]);
	if (!(new_halls = (t_hall *)malloc(sizeof(t_hall) * (map->halls_size + 1))))
		lem_in_print_error();
	new_halls[map->halls_size] = new_hall;
	while (i++ < map->halls_size)
		new_halls[i - 1] = map->halls[i - 1];
	if (map->halls)
		free(map->halls);
	map->next = 0;
	map->halls_size++;
	map->halls = new_halls;
	ft_strdel_double(&split);
}

static void	lem_in_add_tube_line(char *line, t_map *map)
{
	int		i;
	char	**split;
	t_tube	new_tube;
	t_tube	*new_tubes;

	i = 0;
	if (!(split = ft_strsplit(line, '-')))
		lem_in_print_error();
	if (!(new_tube.name1 = ft_strdup(split[0])))
		lem_in_print_error();
	if (!(new_tube.name2 = ft_strdup(split[1])))
		lem_in_print_error();
	if (!(new_tubes = (t_tube *)malloc(sizeof(t_tube) * (map->tubes_size + 1))))
		lem_in_print_error();
	new_tubes[map->tubes_size] = new_tube;
	while (i++ < map->tubes_size)
		new_tubes[i - 1] = map->tubes[i - 1];
	if (map->tubes)
		free(map->tubes);
	map->tubes_size++;
	map->tubes = new_tubes;
	ft_strdel_double(&split);
}

static int	lem_in_line_is_valid(char *line, t_map *map)
{
	int		is_valid;
	int		line_type;

	is_valid = 1;
	line_type = lem_in_line_type(line);
	if (line_type == CMD_START && map->start == -1 && (map->next = HALL_LINE))
		map->start = map->halls_size;
	else if (line_type == CMD_END && map->end == -1 && (map->next = HALL_LINE))
		map->end = map->halls_size;
	else if (map->state == ANT_LINE && line_type == ANT_LINE &&
			(map->state = HALL_LINE))
		map->ant_nb = ft_atoi(line);
	else if (map->state == HALL_LINE && line_type == HALL_LINE)
		lem_in_add_hall_line(line, map);
	else if (((map->state == HALL_LINE && map->next != HALL_LINE) || map->state
			== TUBE_LINE) && line_type == TUBE_LINE && (map->state = TUBE_LINE))
		lem_in_add_tube_line(line, map);
	else if (line_type != CMD_UNKNOWN && line_type != COMMENT)
		is_valid = -1;
	return (is_valid);
}

void		lem_in_get_infos(t_map *map)
{
	int		res;
	char	*line;
	char	**read;

	res = 1;
	line = NULL;
	read = NULL;
	while (res > 0)
	{
		if ((res = get_next_line(0, &line)) == -1)
			lem_in_print_error();
		if (line && line[0] != 0 && lem_in_line_is_valid(line, map) != -1)
			read = lem_in_join_line(&line, &read);
		else
			break ;
	}
	map->entry = read;
}
