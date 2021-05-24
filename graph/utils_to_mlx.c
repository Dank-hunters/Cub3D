/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:08:12 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/24 21:01:55 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define WIN_X 1920

void initss(t_info *map)
{
	map->vert_x = 0;
	map->vert_y = 0;
	map->horz_x = 0;
	map->horz_y = 0;
	map->turnleft = 0;
	map->turnright = 0;
	map->fov = 60;
	if (map->view_d == 'S')
		map->angle_vision = 270; 
	if (map->view_d == 'N')
		map->angle_vision = 90; 
	if (map->view_d == 'W')
		map->angle_vision = 180; 
	if (map->view_d == 'E')
		map->angle_vision = 0; 
	map->angle_ray = map->angle_vision + 30 ;
	map->proj = (map->res_x / 2) / tan((map->fov/2) * (M_PI/180));
	map->gap = ((float)map->fov / (float)map->res_x);
}

int		keypress(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 1;
	if (key == KEY_RIGHT)
		map->turnright = 1;
	return (1);
}

int		keyrelease(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 0;
	if (key == KEY_RIGHT)
		map->turnright = 0;
	return (1);
}

int		graph(t_info *map)
{

	//t_data	img;
	//t_coord x_y;
	int i;
	
	i = 0;

	initss(map);
		dprintf(1, "%f\n", map->gap);
	map->img.mlx = mlx_init();
	
	map->img.mlx_win = mlx_new_window(map->img.mlx, map->res_x, map->res_y, "Hello world!");
	if (map->img.mlx_win == NULL)
		dprintf(1, "win creation failled");
	map->img.img = mlx_new_image(map->img.mlx, map->res_x, map->res_y);
	if (map->img.img == NULL)
		dprintf(1, "img creation failled");
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length,
								&map->img.endian);
	if (map->img.addr == NULL)
		dprintf(1, "img creation failled");

//	mlx_loop_hook(map->img.mlx_win, creat_img, map);
	//creat_img(1, map);
	mlx_hook(map->img.mlx_win, 2, 1L << 0, keypress, map);
    mlx_hook(map->img.mlx_win, 3, 1L << 1, keyrelease, map);
	mlx_loop_hook(map->img.mlx, &creat_img, map);
	mlx_loop(map->img.mlx);
	return (1);
}
