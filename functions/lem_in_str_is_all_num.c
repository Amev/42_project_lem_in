#include "lem_in_functions.h"

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
