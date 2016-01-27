#include "lem_in.h"

int			lem_in_line_type(char *line, t_map *map)
{
	if (line[0] && line[0] == '#' && line[1] && line[1] =='#')
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

void		lem_in_add_hall_line(char *line, t_map *map)
{
}

void		lem_in_add_tube_line(char *line, t_map *map)
{
}

int			lem_in_line_is_valid(char *line, t_map *map)
{
	int		is_valid;
	int		line_type;

	is_valid = 1;
	line_type = lem_in_line_type(line);
	if (line_type == CMD_UNKNOWN || line_type == COMMENT)
		is_valid = 0;
	else if (map->state == ANT_LINE && line_type == ANT_LINE)
	{
		map->ant_nb = ft_atoi(line);
		map->state = HALL_LINE;
	}
	else if (map->state == HALL_LINE && line_type == HALL_LINE)
		lem_in_add_hall_line(line, map);
	else if ((map->state == HALL_LINE || map->state == TUBE_LINE) &&
			line_type == TUBE_LINE)
		lem_in_add_tube_line(line, map);
	else
		is_valid = -1;
	return (is_valid);
}

void		lem_in_get_infos(t_map *map)
{
	int		res;
	char	*line;
	char	**read;

	line = NULL;
	read = NULL;
	while (1)
	{
		if ((res = get_next_line(0, &line)) == 0 || line[0] == 0)
			break ;
		if (lem_in_line_is_valid(line, map) == -1)
			break ;
		read = lem_in_join_line(&line, &read);
	}
	map->entry = read;
	lem_in_print_entry(map->entry);
}
