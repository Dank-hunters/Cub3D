/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:30 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/28 20:48:27 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_inter(t_info *map)
{
	if (map->na_ray >= 0 && map->na_ray < 180)
		map->hy = floor(map->py);
	else
		map->hy = floor(map->py) + 1.0f;
	map->hx = map->px + (((float)map->py - map->hy) / \
		tan(map->na_ray * (M_PI / 180)));
	if ((map->a_ray > 0 && map->na_ray <= 90) || \
		(map->na_ray > 270 && map->na_ray <= 360))
		map->vx = floor(map->px) + 1.0f;
	else
		map->vx = floor(map->px);
	map->vy = map->py + (((float)map->px - map->vx) * \
		tan(map->na_ray * (M_PI / 180)));
}

void	found_wall_vert(t_info *map, float ray)
{
	float	add;
	float	less;

	less = 0;
	if (ray >= 90 && ray < 270)
		less = 0.0001;
	add = tan(ray * (M_PI / 180));
	while ((map->vx - less) >= 0 && (map->vx - less) < map->line_size \
		&& map->vy >= 0 && map->vy < map->line_compt \
		&& map->map[(int)map->vy][(int)(map->vx - less)] == '.')
	{
		if ((ray >= 0 && ray < 90) || (ray >= 270 && ray <= 360))
		{
			map->vx = map->vx + 1;
			map->vy = map->vy - add;
		}
		else
		{
			map->vx = map->vx - 1;
			map->vy = map->vy + add;
		}
	}
	map->v_dist = sqrt(pow(map->vx - map->px, 2)
			+ pow(map->vy - map->py, 2));
}

void	found_wall_hor(t_info *map, float ray)
{
	float	add;
	float	less;

	less = 0;
	if (ray >= 0 && ray < 180)
		less = 0.0001;
	add = 1 / tan(ray * (M_PI / 180));
	while (map->hx >= 0 && map->hx < map->line_size
		&& (map->hy - less) >= 0 && (map->hy - less) < map->line_compt
		&& map->map[(int)(map->hy - less)][(int)map->hx] == '.')
	{
		if ((ray >= 0 && ray < 90) || (ray >= 90 && ray < 180))
		{
			map->hy = map->hy - 1;
			map->hx = map->hx + add;
		}
		else
		{
			map->hy = map->hy + 1;
			map->hx = map->hx - add;
		}
	}
	map->h_dist = sqrt(pow(map->hx - map->px, 2)
			+ pow(map->hy - map->py, 2));
}
