/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:51:53 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:06:46 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define CMD_END 1
# define CMD_START 2
# define CMD_UNKNOWN 3

# define COMMENT -1

# define MAP_LINE 0
# define ANT_LINE 10
# define HALL_LINE 20
# define TUBE_LINE 30
# define INVALID_LINE 40

# include "../functions/lem_in_functions.h"

typedef struct		s_hall
{
	char			*name;
	int				x;
	int				y;
}					t_hall;

typedef struct		s_tube
{
	char			*name1;
	char			*name2;
	int				index1;
	int				index2;
}					t_tube;

typedef struct		s_node
{
	t_hall			hall;
	int				*links;
	int				links_size;
	int				is_available;
	int				is_start;
	int				is_end;
	int				weight;
	int				father;
	int				tag;
	int				ant;
}					t_node;

typedef struct		s_ant
{
	int				name;
	int				node;
}					t_ant;

typedef struct		s_path
{
	int				*path;
	int				extra;
	int				len;
}					t_path;

typedef struct		s_map
{
	char			**entry;
	char			state;
	int				ant_nb;
	t_tube			*tubes;
	t_hall			*halls;
	int				start;
	int				end;
	int				halls_size;
	int				tubes_size;
	int				graph_size;
	int				paths_size;
	int				next;
	t_node			*graph;
	t_path			*paths;
	int				shortest_len;
	int				shortest_path;
	t_ant			*ants;
	int				ants_start;
}					t_map;

void				lem_in_get_infos(t_map *map);
void				lem_in_graph_constructor(t_map *map);
int					lem_in_pathfinding(t_map *map, int **path);
void				lem_in_paths(t_map *map);
void				lem_in_ants_moves(t_map *map);

#endif
