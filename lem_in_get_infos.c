#include "lem_in.h"

char		**lem_in_join_line(char **line, char ***read)
{
	size_t	i;
	size_t	len;
	char	**new;

	i = 0;
	len = 0;
	while (*read && (*read)[len])
		len++;
	if (!(new = (char **)malloc(sizeof(char *)  * (len + 2))))
		lem_in_print_error();
	new[len + 1] = NULL;
	while (i++ < len)
		new[i - 1] = (*read)[i - 1];
	new[len] = *line;
	if (*read)
		free(*read);
	return (new);
}

void		lem_in_print_entry(char **read)
{
	int		i;

	i = 0;
	while (read && read[i])
	{
		ft_printf("line %d: %s\n", i, read[i]);
		i++;
	}
}

int			lem_in_line_type(char *line)
{
	if (line[0] && line[0] == '#')
	{
		if (line[1] && line[1] =='#')
		{
			if (ft_strcmp("##start", line) == 0)
				return (CMD_START);
			else if (ft_strcmp("##end", line) == 0)
				return (CMD_END);
			return (CMD_UNKNOWN);
		}
		else
			return (COMMENT);
	}
	return (MAP_LINE);
}

int			lem_in_line_is_valid(char *line, t_map *map)
{
	int		is_valid;
	int		line_type;

	line_type = lem_in_line_type(line);
	if (line_type == CMD_UNKNOWN || line_type == COMMENT)
		return (0);
	else if (map->state == ANT_LINE && line_type == MAP_LINE)
		is_valid = lem_in_get_ant_number(line, map);
	else if (map->state == HALL_LINE || map->state == TUBE_LINE
			&& line_type == MAP_LINE)
		is_valid = lem_in_get_map_infos(line, map);
	if (is_valid == -1)
		return (-1);
	return (1);
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
