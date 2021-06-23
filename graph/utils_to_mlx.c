/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:08:12 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/22 16:04:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initss(t_info *map)
{
	map->res_y = RES_Y;
	map->res_x = RES_X;
	map->vx = 0;
	map->vy = 0;
	map->hx = 0;
	map->hy = 0;
	map->turnleft = 0;
	map->turnright = 0;
	map->fov = 60;
	map->fward = 0;
	map->bward = 0;
	map->h_dist = 0;
	if (map->view_d == 'S')
		map->angle_vision = 270;
	if (map->view_d == 'N')
		map->angle_vision = 90;
	if (map->view_d == 'W')
		map->angle_vision = 180;
	if (map->view_d == 'E')
		map->angle_vision = 0;
	map->a_ray = map->angle_vision;
	map->na_ray = map->angle_vision + map->fov * .5f ;
	map->proj = (map->res_x * 0.5f) / tan((map->fov * 0.5f) * (M_PI / 180));
	map->gap = ((float)map->fov / (float)map->res_x);
	map->ccolor = create_trgb(0, map->r_c, map->g_c, map->b_c);
	map->fcolor = create_trgb(0, map->r_f, map->g_f, map->b_f);

}

int	graph(t_info *map)
{
	int	i;

	i = 0;
	mlx_hook(map->img.mlx_win, 2, 1L << 0, keypress, map);
	mlx_hook(map->img.mlx_win, 3, 1L << 1, keyrelease, map);
	if (mlx_loop_hook(map->img.mlx, &creat_img, map) == 1)
		return (0);
	mlx_loop(map->img.mlx);
	return (1);
}
