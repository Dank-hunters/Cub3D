/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:30 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/13 17:41:09 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_inter(t_info *map)
{
	if (map->na_ray >= 0 && map->na_ray <= 180)
		map->hy = floor(map->py) - 0.0001;
	else
		map->hy = floor(map->py) + 1;
	map->hx = map->px + (((float)map->py - map->hy) / \
		tan(map->na_ray * (M_PI / 180)));
	if ((map->a_ray >= 0 && map->na_ray <= 90) || \
		(map->na_ray >= 270 && map->na_ray <= 360))
		map->vx = floor(map->px) + 1.0;
	else
		map->vx = floor(map->px) - 0.0001;
	map->vy = map->py + (((float)map->px - map->vx) * \
		tan(map->na_ray * (M_PI / 180)));
}

void	found_wall_hor(t_info *map, float toadd_y, float toadd_x)
{
	while ((int)map->hx >= 0 && (int)map->hx < map->line_size && \
			(int)map->hy >= 0 && (int)map->hy < map->line_compt && \
			(map->map[(int)map->hy][(int)map->hx] == '.'))
	{
		if (map->na_ray <= 90)
		{
			map->hy = map->hy - toadd_y - 0.0001;
			map->hx = map->hx + toadd_x;
		}
		else if (map->na_ray > 90 && map->na_ray <= 180)
		{
			map->hy = map->hy - toadd_y - 0.0001;
			map->hx = map->hx + toadd_x;
		}
		else if (map->na_ray > 180 && map->na_ray <= 270)
		{
			map->hy = map->hy + toadd_y;
			map->hx = map->hx - toadd_x;
		}
		else if (map->na_ray > 270 && map->na_ray <= 360)
		{
			map->hy = map->hy + toadd_y;
			map->hx = map->hx - toadd_x;
		}
	}
}

void	found_wall_vert(t_info *map, float toadd_y, float toadd_x)
{
	while ((int)map->vx >= 0 && (int)map->vx < map->line_size && \
			(int)map->vy >= 0 && (int)map->vy < map->line_compt && \
			(map->map[(int)map->vy][(int)map->vx] == '.'))
	{
		if (map->na_ray <= 90)
		{
			map->vy = map->vy - toadd_y;
			map->vx = map->vx + toadd_x;
		}
		else if (map->na_ray > 90 && map->na_ray <= 180)
		{
			map->vy = map->vy + toadd_y;
			map->vx = map->vx - toadd_x - 0.0001;
		}
		else if (map->na_ray > 180 && map->na_ray <= 270)
		{
			map->vy = map->vy + toadd_y;
			map->vx = map->vx - toadd_x - 0.0001;
		}
		else if (map->na_ray > 270 && map->na_ray <= 360)
		{
			map->vy = map->vy - toadd_y;
			map->vx = map->vx + toadd_x;
		}
	}
}
