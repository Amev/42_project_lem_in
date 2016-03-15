/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:49:08 by vame              #+#    #+#             */
/*   Updated: 2016/03/11 11:06:03 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_FUNCTIONS_H
# define LEM_IN_FUNCTIONS_H

# include "../libft/libft.h"
# include "../src/lem_in.h"

void				lem_in_print_error(void);
char				**lem_in_join_line(char **line, char ***read);
int					lem_in_str_is_all_num(char *str);
int					lem_in_is_hall_line(char *line);
int					lem_in_is_tube_line(char *line);
void				lem_in_print_entry(char **read);
void				lem_in_print_t_hall(t_hall hall);
void				lem_in_print_t_tube(t_tube tube);
void				lem_in_print_t_map(t_map map);
int					lem_in_map_names(t_map *map);

#endif
