#include "lem_in_functions.h"

void		lem_in_print_entry(char **read)
{
	int		i;

	i = 0;
	while (read && read[i])
	{
		ft_printf("line %d: {grn}%s{eoc}\n", i, read[i]);
		i++;
	}
}
