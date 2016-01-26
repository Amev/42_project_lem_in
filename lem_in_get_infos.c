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
		//lem_in_print_error(ERR_MAL);
		exit(-1);
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

void		lem_in_get_infos(t_map *map)
{
	int		res;
	int		loop;
	char	*line;
	char	**read;

	loop = 1;
	line = NULL;
	read = NULL;
	(void)map;
	while (loop)
	{
		if ((res = get_next_line(0, &line)) == 0 || line[0] == 0)
			break ;
		read = lem_in_join_line(&line, &read);
	}
	lem_in_print_entry(read);
}
