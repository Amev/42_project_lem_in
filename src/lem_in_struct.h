/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:50:06 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:51:42 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

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

#endif
