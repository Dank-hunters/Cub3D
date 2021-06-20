/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:45 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/16 18:33:45 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cut2(t_info *map, int i)
{
	int	y;

	y = 0;
	if (i == 0)
	{
		while (y < map->line_compt)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (rt(0, "there are no player", map));
	}
	if (i >= 2)
	{
		while (y < map->line_compt)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (rt(0, "there are more than 1 spawn point", map));
	}
	return (0);
}

int	ft_found_pos(t_info *map, int i)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map->map[y] != 0)
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'\
					|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
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
	return (cut2(map, i));
}

int	test_map(t_info *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < map->line_compt)
	{
		if (map->map[i][0] == '\0')
		{
			while (y < map->line_compt)
			{
				free_line(map->map[y]);
				y++;
			}
			free(map->map);
			return (rt(0, "-Empty line in middle or a the end of map", map));
		}
		i++;
	}
	return (0);
}

int	parse_map(t_info *map)
{
	int	i;

	i = 0;
	map->tofree = 0;
	if (found_start_map(map) == 1)
		return (1);
	if (init_tab_map(map) == 1)
		return (1);
	if (test_map(map) == 1 || ft_found_pos(map, i) == 1)
		return (1);
	fill_flood_map(map, map->py, map->px);
	if (map->not_close == 6)
	{
		while (i < map->line_compt)
		{
			free_line(map->map[i]);
			i++;
		}
		free(map->map);
		return (rt(0, "The map is not close", map));
	}
	return (0);
}
