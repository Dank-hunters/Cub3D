/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:22:43 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 19:10:22 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cut2(t_info *map, int i, int y)
{
	if (i == 0)
	{
		while (y < map->line_compt)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (error(8));
	}
	if (i >= 2)
	{
		while (y < map->line_compt)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (error(9));
	}
	return (0);
}

int	ft_found_pos(t_info *map, int i, int y)
{
	int	x;

	x = 0;
	while (map->map[y] != NULL)
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N' \
					|| map->map[y][x] == 'S' || map->map[y][x] == 'E' \
					|| map->map[y][x] == 'W')
			{
				i++;
				map->px = x;
				map->py = y;
				map->view_d = map->map[y][x];
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	if (cut2(map, i, y) > 0)
		return (1);
	return (0);
}

int	fill_flood_map(t_info *map, int x, int y)
{
	if (x < 0 || x >= map->line_size || y < 0 || y >= map->line_compt)
		return (0);
	if (map->map[y][x] == ' ')
		return (0);
	if (map->map[y][x] == '.' || map->map[y][x] == '1')
		return (1);
	if (ft_ischar("NEWS0", map->map[y][x]) == 1)
		map->map[y][x] = '.';
	if (fill_flood_map(map, x + 1, y) == 1
		&& fill_flood_map(map, x - 1, y) == 1
		&& fill_flood_map(map, x, y + 1) == 1
		&& fill_flood_map(map, x, y - 1) == 1)
		return (1);
	else
		return (0);
}
