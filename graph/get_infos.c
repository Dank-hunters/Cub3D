/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:30 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/21 18:13:20 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*int init_vars(t_idd *value, t_info *map, t_map *cub)
{
	if (0)
		cub->map = NULL;
	value->gap =(int)sqrt(pow(map->res_y, 2) + pow(map->res_x, 2)) 2*(tan(fov/2));
	value->fov = M_PI/3;

	dprintf(1, "\n%i\n%i\n%i", value->gap, map->res_y, map->res_x);
	return (0);
}
*/
void	first_horz(t_map *cub)
{
	dprintf(1, "\nle x : %f, le y : %f", cub->horz_x, cub->horz_y);
//	cub->map[(int)cub->pos_y][(int)cub->pos_x] = '.';
	if (cub->angle_ray >= 0 && cub->angle_ray <= 180)
		cub->horz_y = floor(cub->pos_y) + 1;
	else
		cub->horz_y = floor(cub->pos_y);
	
	cub->horz_x = (float)cub->pos_x + (((float)cub->pos_y - (float)cub->horz_y )/tan(cub->angle_ray * (M_PI/180)));
		dprintf(1, "\nle x : %f, le y : %f", cub->horz_x, cub->horz_y);
}

void first_vert(t_map *cub)
{
		//cub->map[(int)cub->pos_y][(int)cub->pos_x] = '.';
	if ((cub->angle_ray >= 0 && cub->angle_ray <= 90) || (cub->angle_ray >= 270 && cub->angle_ray <= 360))
		cub->vert_x = (float)floor(cub->pos_x) + 1.0;
	else 
		cub->vert_x = (float)floor(cub->pos_x);
	cub->vert_y = (float)cub->pos_y + (((float)cub->pos_x - (float)cub->vert_x) * tan(cub->angle_ray * (M_PI/180)));

}
void found_wall_hor(t_map *cub, t_info *map)
{
	float toadd_x;
	float toadd_y;


	toadd_y = 1.0;
	toadd_x = 1/tan(cub->angle_ray * (M_PI/180));

	dprintf(1, "\nle x : %f, le y : %f", cub->horz_x, cub->horz_y);
	while ((int)cub->horz_x < map->line_size && \
			(int)cub->horz_y < map->line_compt && \
			(int)cub->horz_y >= 0 && \
			(int)cub->horz_x >= 0  &&\
			(cub->map[(int)cub->horz_y][(int)cub->horz_x] == '.' && \
			(cub->map[(int)cub->horz_y][(int)cub->horz_x] == 'N' ||\
			cub->map[(int)cub->horz_y][(int)cub->horz_x] == 'W' ||\
			cub->map[(int)cub->horz_y][(int)cub->horz_x] == 'E' ||\
			cub->map[(int)cub->horz_y][(int)cub->horz_x] == 'S')))
	{
	//	dprintf(1, "coucou");			
		if (cub->angle_ray >= 0 && cub->angle_ray <= 90)	
		{
			cub->horz_y += toadd_y;
			cub->horz_x += toadd_x;
		}
		else if (cub->angle_ray > 90 && cub->angle_ray <= 180)
		{
			cub->horz_y -= toadd_y;
			cub->horz_x += toadd_x;
		}
		else if (cub->angle_ray > 180 && cub->angle_ray <= 270)
		{
			cub->horz_y -= toadd_y;
			cub->horz_x += toadd_x;
		}
		else if (cub->angle_ray > 270 && cub->angle_ray <= 360)
		{
			cub->horz_y -= toadd_y;
			cub->horz_x -= toadd_x;
		}
		dprintf(1, "\nle x : %f, le y : %f", cub->horz_x, cub->horz_y);
	}
	//cub->map[(int)cub->horz_y][(int)cub->horz_x] = 'H';
}

void found_wall_vert(t_map *cub, t_info *map)
{
	float toadd_x;
	float toadd_y;

	toadd_x = 1;
	toadd_y = tan(cub->angle_ray * (M_PI/180));
//	dprintf(1, "\nle 1x : %f, le y : %f\n", cub->vert_x, cub->vert_y);
	while ((int)cub->vert_x >= 0 && \
		(int)cub->vert_x < map->line_size && \
		(int)cub->vert_y >= 0 && \
		(int)cub->vert_y < map->line_compt &&\
		(cub->map[(int)cub->vert_y][(int)cub->vert_x] == '.' && \
		(cub->map[(int)cub->vert_y][(int)cub->vert_x] == 'N' || \
		cub->map[(int)cub->vert_y][(int)cub->vert_x] == 'E' ||\
		cub->map[(int)cub->vert_y][(int)cub->vert_x] == 'W' ||\
		cub->map[(int)cub->vert_y][(int)cub->vert_x] == 'S')))
	{
//	dprintf(1, "\nvertt");
//dprintf(1, "coucou2");
		if (cub->angle_ray >= 0 && cub->angle_ray <= 90)	
		{
			cub->vert_y -= toadd_y;
			cub->vert_x += toadd_x;
		}
		else if (cub->angle_ray > 90 && cub->angle_ray <= 180)
		{
			cub->vert_y += toadd_y;
			cub->vert_x -= toadd_x;
		}
		else if (cub->angle_ray > 180 && cub->angle_ray <= 270)
		{
			cub->vert_y += toadd_y;
			cub->vert_x -= toadd_x;
		}
		else if (cub->angle_ray > 270 && cub->angle_ray <= 360)
		{
			cub->vert_y -= toadd_y;
			cub->vert_x += toadd_x;	
		}
	}
//	dprintf(1, "\nle x : %f, le y : %f\n", cub->vert_x, cub->vert_y);
//	cub->map[(int)cub->vert_y][(int)cub->vert_x] = 'V';
}