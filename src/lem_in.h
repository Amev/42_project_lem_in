/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:51:53 by vame              #+#    #+#             */
/*   Updated: 2016/03/15 10:21:30 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "./lem_in_struct.h"
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

void				lem_in_get_infos(t_map *map);
void				lem_in_graph_constructor(t_map *map);
int					lem_in_pathfinding(t_map *map, int **path);
void				lem_in_paths(t_map *map);
void				lem_in_ants_moves(t_map *map);

#endif
