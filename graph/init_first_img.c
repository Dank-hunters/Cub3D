/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:49:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/23 20:17:18 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void	my_mlx_pixel_put(t_info *map, int x, int y, int color)
{
	char	*dst;

	//dprintf(1, "il le fait");
	dst = map->img.addr + (y * map->img.line_length + x * (map->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clear_my_win(t_info *map)
{
	int y;
	int x;

	x = map->res_x;
	y = map->res_y;
	while(x > 0)
	{
		while(y > 0)
		{
			if (x >= 0 && x < map->res_x && y >= 0 && y < map->res_y )
				my_mlx_pixel_put(map, x, y, 0xFF0000);
			y--;
		}
		x--;
	}

}
int	creat_img(int keycode, t_info *map)
{
	int	i;
	int angle_ray;

	
	i = 0;
	(void)keycode;
	clear_my_win(map);
	//if (keycode == 123 )
//	/	map->angle_ray += 3;
//	if (keycode == 124)
//		map->angle_ray -= 3;
	angle_ray = map->angle_ray;
	while(i < map->res_x)
	{
		first_horz(map, angle_ray);
		first_vert(map, angle_ray);
		found_wall_hor(map, angle_ray);
		found_wall_vert(map, angle_ray);
		map->h_dist = (float)sqrt((float)pow(map->horz_x - map->pos_x, 2) + (float)pow(map->horz_y - map->pos_y, 2));
		map->v_dist = (float)sqrt((float)pow(map->vert_x - map->pos_x, 2) + (float)pow(map->vert_y - map->pos_y, 2));
		//dprintf(1, "vdist = %f, vx = %f vy = %f hdist = %f hx = %f hy = %f\n", map->v_dist, map->vert_x, map->vert_y, map->h_dist, map->horz_x, map->horz_y);
		creat_col(map, i/*, map->img*/);
		angle_ray -= map->gap;
		//dprintf(1, " %f\n", map->angle_ray);
		i++;
	}


	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->img.img, 0, 0);
	return (1);
}

void	creat_col(t_info *map, int x/*, t_data *img*/)
{
	float dist;
	int h_wall;
	int i;
	float y;

	
	i = 0;
	h_wall = 0;
	if (map->h_dist >= map->v_dist)
			dist = map->v_dist;
	else 
			dist = map->h_dist;
		h_wall = (float)1/dist * (int)map->proj;
		y = ((map->res_y/2) + (h_wall/2));

	while(h_wall)
	{
		//dprintf(1, "x = %d y = %d\n", x, (map->res_y/2 - i));
		if (x >= 0 && x < map->res_x && y >= 0 && y < map->res_y )
	{
				my_mlx_pixel_put(map, x, y, 0xFFFFFF);
			//	my_mlx_pixel_put(img, x, i, 0xFF0000);
	}
		h_wall--;
		y --;
		i++;
	}

}

