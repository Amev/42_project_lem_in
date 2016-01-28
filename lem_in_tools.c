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

int			lem_in_str_is_all_num(char *str)
{
	while (str && *str)
	{
		if (!ft_isdigit((int)(*str)))
			return (0);
		str++;
	}
	return (1);
}

int			lem_in_is_hall_line(char *line)
{
	int		i;
	int		ret;
	char	**split;

	i = 1;
	ret = 1;
	if (!(split = ft_strsplit(line, ' ')))
		lem_in_print_error();
	if (!split[0] && split[0][0] == 'L')
		ret = 0;
	while (ret && split[i])
		if (!lem_in_str_is_all_num(split[i++]))
			ret = 0;
	if (ret && i != 3)
		ret = 0;
	ft_strdel_double(&split);
	return (ret);
}

int			lem_in_is_tube_line(char *line)
{
	int		i;
	int		ret;
	char	**split;

	i = 0;
	ret = 1;
	if(!(split = ft_strsplit(line, '-')))
		lem_in_print_error();
	while (ret && split[i] && i < 3)
		i++;
	if (i != 2)
		ret = 0;
	ft_strdel_double(&split);
	return (ret);
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
