/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:49:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/12 21:37:34 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_info *map, int x, int y, int color)
{
	char	*dst;

	dst = (char *)map->img.addr + (y * map->img.line_length + x * (map->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	*get_pixel_loc(t_info *map, int x, int y)
{
	char	*dst;

	dst = (char *)map->img.addr + (y * map->img.line_length + x * (map->img.bits_per_pixel / 8));
	return (unsigned int *)dst;
}

void	clear_my_win(t_info *map)
{
	int y;
	int x;

	x = map->res_x;
	while (x > 0)
	{
		y = map->res_y;
		while (y > 0)
		{
			if (x >= 0 && x < map->res_x && y >= 0 && y < map->res_y )
				*get_pixel_loc(map, x, y) = create_trgb(0,map->r_floor, map->g_floor, map->b_floor);
			y--;
		}
		x--;
	}

}

void draw_col(t_info *map, int x, int wall_height)
{
	int	y;
	int	limit;
	unsigned int	*loc;

	y = 0;
	limit = (map->res_y / 2) - (wall_height / 2);
	loc = get_pixel_loc(map, x, 0);
	while (y < limit)
	{
		*get_pixel_loc(map, x, y++) = 0x000000FF;
		// *loc = 0x000000FF;
		// loc = (unsigned int *)((unsigned char *)loc + map->img.line_length);
	}
	limit += wall_height;
//	while (y < limit && y < map->res_y)
//		*get_pixel_loc(map, x, y++) = 0x00FFFFFF;
	while (y < map->res_y)
		*get_pixel_loc(map, x, y++) = 0x00BAABAB;
	// while (i < map->h_wall)
	// {
	// 	if (x >= 0 && x < map->res_x && y - i >= 0 && y - i < map->res_y )		
	// 		*get_pixel_loc(map, x, y - i) = 0xB8860B;
	// 	i++;
	// }
	// while (i < map->res_y)
	// {
	// 			if (x >= 0 && x < map->res_x && y - i >= 0 && y - i < map->res_y )
	// 				*get_pixel_loc(map, x, y - i) = 0;
	// 	i++;
	// }
}

void	creat_col(t_info *map, int x, float patch)
{
	float dist;
	int i;
	//float y;

	i = 0;
	if (map->h_dist >= map->v_dist)
		dist = map->v_dist;
	else 
		dist = map->h_dist;
	dist = dist * fabs(cos(patch * (M_PI/180)));
	map->h_wall = 1/dist * map->proj;
	//y = (map->res_y * 0.5f) + (map->h_wall * 0.5f);
	draw_col(map, x, map->h_wall);
		if (map->h_dist < map->v_dist)
            map->winx = (int)(map->horz_x * map->xpm[0].width) % map->xpm[0].width;
    	else 
    		map->winx = (int)(map->vert_y * map->xpm[0].width) % map->xpm[0].width;
	add_text(map, dist, x);

}


int	creat_img(t_info *map)
{
	int	i;
	float	patch;
	
	//clear_my_win(map);
	event(map);
	if (map->angle_ray >= 360)
		map->angle_ray = map->angle_ray - 360.0f;
	if (map->angle_ray < 0)
		map->angle_ray = map->angle_ray + 360.f;
	map->n_angle_ray = map->angle_ray + 30;
	i = 0;
	patch = (map->fov * -.5f) * -1;

	while (i < map->res_x)
	{
		if (map->n_angle_ray >= 360)
			map->n_angle_ray = map->n_angle_ray - 360.0f;
		if (map->n_angle_ray < 0)
			map->n_angle_ray = map->n_angle_ray + 360.f;
		first_inter(map);
		found_wall_hor(map);
		found_wall_vert(map);
		map->h_dist = sqrt(pow(map->horz_x - map->pos_x, 2) + pow(map->horz_y - map->pos_y, 2));
		map->v_dist = sqrt(pow(map->vert_x - map->pos_x, 2) + pow(map->vert_y - map->pos_y, 2));
		creat_col(map, i, patch);
		map->n_angle_ray = map->n_angle_ray - map->gap;
		patch = patch - map->gap;

		i++;
	}
	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->img.img, 0, 0);
	return (1);
}