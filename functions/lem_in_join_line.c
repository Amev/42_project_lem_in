#include "lem_in_functions.h"

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
