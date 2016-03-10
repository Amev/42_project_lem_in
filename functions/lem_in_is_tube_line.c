/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_is_tube_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:50:51 by vame              #+#    #+#             */
/*   Updated: 2016/03/10 15:04:06 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_functions.h"

int			lem_in_is_tube_line(char *line)
{
	int		i;
	int		ret;
	char	**split;

	i = 0;
	ret = 1;
	if (!(split = ft_strsplit(line, '-')))
		lem_in_print_error();
	while (ret && split[i] && i < 3)
		i++;
	if (i != 2)
		ret = 0;
	ft_strdel_double(&split);
	return (ret);
}
