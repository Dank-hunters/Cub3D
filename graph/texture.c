/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:21:14 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/28 22:48:50 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_to_img(t_info *map)
{
	map->xpm[0].img = mlx_xpm_file_to_image(map->img.mlx, map->pt_no_t,
			&map->xpm[0].width, &map->xpm[0].height);
	free_line(map->pt_no_t);
	map->xpm[1].img = mlx_xpm_file_to_image(map->img.mlx, map->pt_so_t,
			&map->xpm[1].width, &map->xpm[1].height);
	free_line(map->pt_so_t);
	map->xpm[2].img = mlx_xpm_file_to_image(map->img.mlx, map->pt_ea_t,
			&map->xpm[2].width, &map->xpm[2].height);
	free_line(map->pt_ea_t);
	map->xpm[3].img = mlx_xpm_file_to_image(map->img.mlx, map->pt_we_t,
			&map->xpm[3].width, &map->xpm[3].height);
	free_line(map->pt_we_t);
}

int	init_text(t_info *map, int i)
{
	int	error;

	error = 0;
	while (i <= 3)
	{
		if (map->xpm[i].img == NULL)
		{
			while (--i >= 0)
				mlx_destroy_image(map->img.mlx, map->xpm[i].img);
			mlx_destroy_image(map->img.mlx, map->img.img);
			mlx_destroy_window(map->img.mlx, map->img.mlx_win);
			return (rt(0, "path unknow", map));
		}
		else
			map->xpm[i].addr = (int *)mlx_get_data_addr(map->xpm[i].img,
					&map->xpm[i].bpp, &map->xpm[i].line_len,
					&map->xpm[i].endian);
		if (map->xpm[i].addr == NULL)
		{
			error ++;
			break ;
		}
		i++;
	}
	return (error);
}

int	witch_text(t_info *map, int hoz)
{
	int	text;

	text = 0;

	if (hoz == 1 && map->vx - (int)map->vx < 0.5)
		text = 2;
	else if (hoz == 1 && map->vx - (int)map->vx >= 0.5)
		text = 3;
	else if (hoz == 2 && map->hy - (int)map->hy < 0.5)
		text = 1;
	else if (hoz == 2 && map->hy - (int)map->hy >= 0.5)
		text = 0;
	return (text);
}


void	add_text(t_info *map, float dist, int x, int hoz)
{
	int		i;
	float	y;
	float	n_gap;
	int		n;

	i = 0;
	(void)dist;
	y = 0;
	n = witch_text(map, hoz);
	if (hoz == 1)
		map->winx = (int)(map->vy * map->xpm[n].width) % map->xpm[n].width;
	else
		map->winx = (int)(map->hx * map->xpm[n].width) % map->xpm[n].width;
	if (map->winx >= map->xpm[n].width)
		map->winx--;
	while (i < map->h_wall)
	{
		n_gap = (float)map->xpm[n].height / map->h_wall;
		if (map->winy + i >= 0 && map->winy + i < map->res_y && y >= 0 && x < map->res_x &&\
				y < map->xpm[n].height && map->winx >= 0 && \
				map->winx <= map->xpm[n].width)
			map->img.addr[(map->winy + i) * map->res_x + x]
				= map->xpm[n].addr[(int)y * map->xpm[n].width + map->winx];
		i++;
		y = (float)y + n_gap;
	}
}
