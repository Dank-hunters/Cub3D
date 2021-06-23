/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/22 19:55:17 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_ceiling_color(char *line, t_info *map, int	i)
{
	if (line[i] != ' ')
		return (rt(-1, "- After C. ", map));
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (rt(1, "- Before R. ", map));
	map->r_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-1, "- Between R & G. ", map));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-1, "- Between R & G. ", map));
	map->g_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-1, "- Between G & B. ", map));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-1, "- Between G & B. ", map));
	map->b_c = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (rt(-1, "- Too few caracters after B. ", map));
	free_line(line);
	return (0);
}

int	parse_floor_color(char *line, t_info *map, int	i)
{
	if (line[i] != ' ')
		return (rt(-3, "- After idd", map));
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (rt(-3, "- Before G\n", map));
	map->r_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-3, "- Missng ','\n", map));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-3, "- Between R & G\n", map));
	map->g_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-3, "- Between  G & B\n", map));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-3, "- Between  G & B\n", map));
	map->b_f = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (rt(-3, "- Too few characters after B\n", map));
	free_line(line);
	return (0);
}
