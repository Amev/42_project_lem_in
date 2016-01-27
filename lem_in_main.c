#include "lem_in.h"

int			main(void)
{
	t_map	map;

	map.has_end = 0;
	map.has_start = 0;
	map.state = ANT_LINE;
	lem_in_get_infos(&map);
	return (0);
}
