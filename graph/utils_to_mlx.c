/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:08:12 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/21 18:29:36 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	
	//dprintf(1, "il le fait");
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void initss(t_map *cub, t_info *map)
{
	cub->vert_x = 0;
	cub->vert_y = 0;
	cub->horz_x = 0;
	cub->horz_y = 0;
	cub->fov = 60;
	if (cub->view_d == 'S')
		cub->angle_vision = 270; 
	if (cub->view_d == 'N')
		cub->angle_vision = 90; 
	if (cub->view_d == 'W')
		cub->angle_vision = 180; 
	if (cub->view_d == 'E')
		cub->angle_vision = 0; 
	cub->angle_ray = cub->angle_vision + 30 ;
	cub->proj = ((float)map->res_x / 2) / tan(cub->fov/2 * (M_PI/180));
	cub->gap = (float)cub->fov/(float)map->res_x;
}


void	creat_col(t_info *map, int x, t_map *cub, t_data *img)
{
	float dist;
	int h_wall;
	int i = 0;

	h_wall = 0;

	if (cub->h_dist >= cub->v_dist)
		{
			//dprintf(1, "Vertical ");
			dist = cub->v_dist;
		}
	else 
		{
			//dprintf(1, "Horizontal");
			dist = cub->h_dist;
		}
		h_wall = 1/dist * (int)cub->proj;
	//dprintf(1, "vdist = %f hdist = %F h_wall = %d\n", cub->v_dist, cub->h_dist, h_wall);
	//dprintf(1, "vdist = %f, vx = %f vy = %f hdist = %f hx = %f hy = %f\n", cub->v_dist, cub->vert_x, cub->vert_y, cub->h_dist, cub->horz_x, cub->horz_y);
	
	while(i < h_wall)
	{
		//dprintf(1, "x = %d y = %d\n", x, (map->res_y/2 - i));
		if (x >= 0 && x < map->res_x && (map->res_y/2 - i) >= 0 && (map->res_y/2 - i) < map->res_y)
			my_mlx_pixel_put(img, x, (map->res_y/2 - i), 0xFFFFFF);
		i++;
	}
}

int	key_hook(int keycode, t_map *cub)
{
	if (keycode == 123 )
		cub->angle_ray += 3;
	if (keycode == 124)
		cub->angle_ray -= 3;
	dprintf(1, "%i\n", keycode);
	return(0);
}

int		graph(t_info *map, t_map *cub)
{

	t_data	img;
	//t_coord x_y;
	int i;
	
	i = 0;
	initss(cub, map);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, map->res_x, map->res_y, "Hello world!");
//	if (img.mlx_win == NULL)
	//	dprintf(1, "win creation failled");
	img.img = mlx_new_image(img.mlx, map->res_x, map->res_y);
//	if (img.img == NULL)
//		dprintf(1, "img creation failled");
	//dprintf(1, "success");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 100, 100, 0xFFFFFF);
	
	while(i < map->res_x)
{
		
	//	dprintf(1, "le I laaaaaaaaa %i", i);
	
		first_horz(cub);
		first_vert(cub);
		found_wall_hor(cub, map);
		found_wall_vert(cub, map);
		cub->h_dist = sqrt(pow(cub->horz_x - cub->pos_x, 2) + pow(cub->horz_y - cub->pos_y, 2));
		cub->v_dist = sqrt(pow(cub->vert_x - cub->pos_x, 2) + pow(cub->vert_y - cub->pos_y, 2));
		dprintf(1, "vdist = %f, vx = %f vy = %f hdist = %f hx = %f hy = %f\n", cub->v_dist, cub->vert_x, cub->vert_y, cub->h_dist, cub->horz_x, cub->horz_y);
		creat_col(map, i, cub, &img);

		cub->angle_ray -= cub->gap;
		//dprintf(1, " %f\n", cub->angle_ray);
		i++;
	}
	//dprintf(1, "\nle x : %f, le y : %f\n", cub->horz_x, cub->horz_y);
	//dprintf(1, "\nle x : %f, le y : %f\n", cub->vert_x, cub->vert_y);
	
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
//	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
	return (1);
}
