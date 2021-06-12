/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:08:12 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/12 21:11:33 by cguiot           ###   ########lyon.fr   */
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
	map->forward = 0;
	map->backward = 0;
	map->h_dist = 0;
	if (map->view_d == 'S')
		map->angle_vision = 270; 
	if (map->view_d == 'N')
		map->angle_vision = 90; 
	if (map->view_d == 'W')
		map->angle_vision = 180; 
	if (map->view_d == 'E')
		map->angle_vision = 0; 
	map->angle_ray = map->angle_vision;
	map->n_angle_ray = map->angle_vision + 30 ;
	map->proj = (map->res_x / 2) / tan((map->fov/2) * (M_PI/180));
	map->gap = ((float)map->fov / (float)map->res_x);
}



int		graph(t_info *map)
{
	int i;
	
	i = 0;
	
	mlx_hook(map->img.mlx_win, 2, 1L << 0, keypress, map);
    mlx_hook(map->img.mlx_win, 3, 1L << 1, keyrelease, map);
	if  (mlx_loop_hook(map->img.mlx, &creat_img, map) == 1)
		return(0);
	mlx_loop(map->img.mlx);
	return (1);
}
