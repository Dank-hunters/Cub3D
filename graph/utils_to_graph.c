/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:03:42 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/21 15:19:50 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_games(t_info *map)
{
	free_map(map);
	exit(0);
	return (190);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	init_imp(t_info *map)
{
	map->map[(int)map->py][(int)map->px] = '.';
	initss(map);
	map->img.mlx = mlx_init();
	map->img.mlx_win = mlx_new_window(map->img.mlx, map->res_x,
			map->res_y, "Cub3d.exe");
	if (map->img.mlx_win == NULL)
		return (error(12));
	map->img.img = mlx_new_image(map->img.mlx, map->res_x, map->res_y);
	if (map->img.img == NULL)
		return (error(13));
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
	if (map->img.addr == NULL)
		return (error(14));
	file_to_img(map);
	if (init_text(map, 0, 0) >= 1)
		return (1);
	return (0);
}
