/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:54:15 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/12 21:19:29 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


int		keypress(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 1;
	if (key == KEY_RIGHT)
		map->turnright = 1;
	if (key == KEY_FORWARD)
		map->forward = 1;
	if (key == KEY_BACKWARD)
		map->backward  = 1;
	if (key == KEY_LEAVE)
		map->esc = 1;
	if (key == KEY_GOLEFT)
		map->goleft = 1;
	if (key == KEY_GORIGHT)
		map->goright = 1;
	return (1);
}

int		keyrelease(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 0;
	if (key == KEY_RIGHT)
		map->turnright = 0;
	if (key == KEY_FORWARD)
		map->forward = 0;
	if (key == KEY_BACKWARD)
		map->backward = 0;
	if (key == KEY_LEAVE)
		map->esc = 0;
	if (key == KEY_GOLEFT)
		map->goleft = 0;
	if (key == KEY_GORIGHT)
		map->goright = 0;
	//dprintf(1, "keycode : %i\n", key);
	return (1);
}

int collision(t_info *map, int x,int y)
{
	if (map->map[y][x] == '.')
		return (0);
	return (1);

}

void    forback(t_info *map)
{  
    float   adds;
	float	addc;

    adds =  (0.20 * (sin((map->angle_ray) * (M_PI/180))));
    addc = (0.20 * (cos((map->angle_ray) * (M_PI/180))));
	if (map->forward == 1 && collision(map, map->pos_x + addc, map->pos_y - adds) == 0)
   	{
        map->pos_x = map->pos_x + addc;
	    map->pos_y = map->pos_y - adds;

    }
    if (map->backward == 1 && collision(map, map->pos_x + (-0.25 * (cos((map->angle_ray ) * (M_PI/180)))), map->pos_y - (-0.25 * (sin((map->angle_ray ) * (M_PI/180))))) == 0)
	{
        map->pos_x = map->pos_x + (-0.20 * (cos((map->angle_ray ) * (M_PI/180))));
		map->pos_y = map->pos_y - (-0.20 * (sin((map->angle_ray ) * (M_PI/180))));
    }
    if (map->goleft == 1 && collision(map, map->pos_x - adds, map->pos_y - addc) == 0)
	{
    	map->pos_x = map->pos_x - adds;
		map->pos_y = map->pos_y - addc;
    }
    if (map->goright == 1 && collision(map, map->pos_x + adds, map->pos_y + addc) == 0)
	{
    	map->pos_x = map->pos_x + adds;
        map->pos_y = map->pos_y + addc;
    }
}

void			event(t_info *map)
{
	if (map->turnleft == 1)
		map->angle_ray += 2;
	if (map->turnright == 1)
		map->angle_ray -= 2;
        forback(map);
	if (map->esc == 1)
		mlx_destroy_window(map->img.mlx, map->img.mlx_win);
	if (map->esc == 1)
		exit(0);
}