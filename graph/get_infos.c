/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:30 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/25 20:58:43 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_horz(t_info *map, float angle_ray)
{
	if (angle_ray >= 0 && angle_ray <= 180) 
		map->horz_y = floor(map->pos_y) - 0.001;
	else
		map->horz_y = floor(map->pos_y);
	map->horz_x = map->pos_x + (((float)map->pos_y - map->horz_y )/ tan(angle_ray * (M_PI/180)));
}

void first_vert(t_info *map, float angle_ray)
{
	if ((angle_ray >= 0 && angle_ray <= 90) || (angle_ray >= 270 && angle_ray <= 360))
		map->vert_x = floor(map->pos_x) + 1.0;
	else 
		map->vert_x = floor(map->pos_x) - 0.001;
	map->vert_y = map->pos_y + (((float)map->pos_x - map->vert_x) * tan(angle_ray * (M_PI/180)));
}

void found_wall_hor(t_info *map, float angle_ray)
{
	float toadd_x;
	float toadd_y;


	toadd_y = 1.0f;
	toadd_x = 1/tan(angle_ray * (M_PI/180));
	while ((int)map->horz_x >= 0  && \
			(int)map->horz_x < map->line_size && \
			(int)map->horz_y >= 0 && \
			(int)map->horz_y < map->line_compt && \
			(map->map[(int)map->horz_y][(int)map->horz_x] == '.' || \
			(map->map[(int)map->horz_y][(int)map->horz_x] == 'N' ||\
			map->map[(int)map->horz_y][(int)map->horz_x] == 'W' ||\
			map->map[(int)map->horz_y][(int)map->horz_x] == 'E' ||\
			map->map[(int)map->horz_y][(int)map->horz_x] == 'S')))
	{
		if (angle_ray <= 90)
		{
			map->horz_y = map->horz_y -toadd_y - 0.00001;
			map->horz_x = map->horz_x + toadd_x;
		}
		else if (angle_ray > 90 && angle_ray <= 180)
		{
			map->horz_y = map->horz_y - toadd_y - 0.00001;
			map->horz_x = map->horz_x + toadd_x;
		}
		else if (angle_ray > 180 && angle_ray <= 270)
		{
			map->horz_y = map->horz_y + toadd_y;
			map->horz_x = map->horz_x - toadd_x;
		}
		else if (angle_ray > 270 && angle_ray <= 360)
		{
			map->horz_y = map->horz_y + toadd_y;
			map->horz_x = map->horz_x - toadd_x;
		}
		
	}
}

void found_wall_vert(t_info *map, float angle_ray)
{
	float toadd_x;
	float toadd_y;

	toadd_x = 1.0f;
	toadd_y = tan(angle_ray * (M_PI/180));
	while ((int)map->vert_x >= 0 && \
		(int)map->vert_x < map->line_size && \
		(int)map->vert_y >= 0 && \
		(int)map->vert_y < map->line_compt && \
		(map->map[(int)map->vert_y][(int)map->vert_x] == '.' || \
		(map->map[(int)map->vert_y][(int)map->vert_x] == 'N' || \
		map->map[(int)map->vert_y][(int)map->vert_x] == 'E' || \
		map->map[(int)map->vert_y][(int)map->vert_x] == 'W' || \
		map->map[(int)map->vert_y][(int)map->vert_x] == 'S')))
	{

		if (angle_ray <= 90)
		{
			map->vert_y = map->vert_y - toadd_y;
			map->vert_x = map->vert_x + toadd_x;
		}
		else if (angle_ray > 90 && angle_ray <= 180)
		{
			map->vert_y = map->vert_y + toadd_y;
			map->vert_x = map->vert_x - toadd_x  - 0.00001;
			
		}
		else if (angle_ray > 180 && angle_ray <= 270)
		{
			map->vert_y = map->vert_y + toadd_y;
			map->vert_x = map->vert_x - toadd_x - 0.00001;
		}
		else if (angle_ray > 270 && angle_ray <= 360) 		
		{
			map->vert_y = map->vert_y - toadd_y;
			map->vert_x = map->vert_x + toadd_x ;
		}
		
	}
}
