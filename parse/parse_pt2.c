/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 17:30:59 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_spe(char *line)
{
	if (line != NULL)
		free(line);
	line = NULL;
}

int	parse_ceiling_color(char *line, t_info *map, int	i)
{
	if (line[i] != ' ')
		return (1);
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (1);
	map->r_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1);
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1);
	map->g_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1);
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1);
	map->b_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (1);
	free_spe(line);
	return (0);
}

int	parse_floor_color(char *line, t_info *map, int	i)
{
	if (line[i] != ' ')
		return (1);
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (1);
	map->r_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1);
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1);
	map->g_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1);
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1);
	map->b_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (1);
	free_spe(line);
	return (0);
}
