/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:49:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/28 22:48:52 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	*get_pixel_loc(t_info *map, int x, int y)
{
	char	*dst;

	dst = (char *)map->img.addr + (y * map->img.line_len + x
			* (map->img.bpp / 8));
	return ((unsigned int *)dst);
}

void	draw_col(t_info *map, int x, int wall_height)
{
	int	y;
	int	limit;

	y = 0;
	limit = (map->res_y / 2) - (wall_height / 2);
	while (y < limit)
	{
		if (x < map->res_x && y < map->res_y)
			*get_pixel_loc(map, x, y++) = map->fcolor ;
	}
	limit += wall_height;
	while (y < map->res_y)
	{
		if (x < map->res_x && y < map->res_y)
			*get_pixel_loc(map, x, y++) = map->ccolor;
	}
}

void	creat_col(t_info *map, int x, float patch)
{
	float	dist;
	int		i;
	int		hoz;

	hoz = 0;
	i = 0;
	if (map->h_dist >= map->v_dist)
	{
		hoz = 1;
		dist = map->v_dist * cos(patch * (M_PI/180));
	}
	else
	{
		hoz = 2;
		dist = map->h_dist * cos(patch * (M_PI/180));
	}
	map->h_wall = 1 / dist * map->proj;
	map->winy = (map->res_y / 2) - (map->h_wall / 2);
	if (map->na_ray >= 90 && map->na_ray < 270)
		map->vx -= 0.0001;
	if (map->na_ray >= 0 && map->na_ray < 180)
		map->hy -= 0.0001;
	draw_col(map, x, map->h_wall);
	add_text(map, dist, x, hoz);
}

static inline float	turnback(float	angle)
{
	if (angle >= 360)
		angle = angle - 360.0f;
	if (angle < 0)
		angle = angle + 360.f;
	return (angle);
}

int	creat_img(t_info *map)
{
	int		i;
	float	patch;

	event(map);
	map->a_ray = turnback(map->a_ray);
	map->na_ray = map->a_ray + map->fov * .5f ;
	i = 0;
	patch = (map->fov * -.5f) * -1;
	while (i < map->res_x)
	{
		map->na_ray = turnback(map->na_ray);
		first_inter(map);
		found_wall_hor(map, map->na_ray);
		found_wall_vert(map, map->na_ray);
		creat_col(map, i, patch);
		map->na_ray = map->na_ray - map->gap;
		patch = patch - map->gap;
		i++;
	}
	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->img.img, 0, 0);
	return (1);
}
