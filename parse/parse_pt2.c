/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/25 17:21:37 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_res(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(-2, "- Before resolution data"));
	i = skip_space(line, i);
	if (line[i] <= '0' && line[i] >= '9')
		return (rt(-2, "- In DPI"));
	map->res_x = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ' ')
		return (rt(-2, "- Between X & Y"));
	i = skip_space(line, i);
	if (line[i] <= '0' && line[i] >= '9')
		return (rt(-2, "- In DPI"));
	map->res_y = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (rt(-2, "- Too few caracteres after resolution data"));
	if (map->res_x >= 5120)
		return (rt(-2, "- The X interval is too long"));
	if (map->res_y >= 2880)
		return (rt(-2, "- The Y interval is too long"));
	return (0);
}

int	parse_ceiling_color(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(-1, "- After C. "));
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (rt(1, "- Before R. "));
	map->r_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-1, "- Between R & G. "));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-1, "- Between R & G. "));
	map->g_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-1, "- Between G & B. "));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-1, "- Between G & B. "));
	map->b_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (rt(-1, "- Too few caracters after B. "));
	return (0);
}

int	parse_floor_color(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(-3, "- After idd"));
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (rt(-3, "- Before G\n"));
	map->r_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-3, "- Missng ','\n"));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-3, "- Between R & G\n"));
	map->g_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (rt(-3, "- Between  G & B\n"));
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (rt(-3, "- Between  G & B\n"));
	map->b_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return (rt(-3, "- Too few characters after B\n"));
	return (0);
}
