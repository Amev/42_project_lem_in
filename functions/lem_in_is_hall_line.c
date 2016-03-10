/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_is_hall_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:50:33 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:05:59 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_functions.h"

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
