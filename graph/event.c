/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:54:15 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/21 15:46:23 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 1;
	if (key == KEY_RIGHT)
		map->turnright = 1;
	if (key == KEY_FORWARD)
		map->fward = 1;
	if (key == KEY_BACKWARD)
		map->bward = 1;
	if (key == KEY_LEAVE)
		map->esc = 1;
	if (key == KEY_GOLEFT)
		map->goleft = 1;
	if (key == KEY_GORIGHT)
		map->goright = 1;
	return (1);
}

int	keyrelease(int key, t_info *map)
{
	if (key == KEY_LEFT)
		map->turnleft = 0;
	if (key == KEY_RIGHT)
		map->turnright = 0;
	if (key == KEY_FORWARD)
		map->fward = 0;
	if (key == KEY_BACKWARD)
		map->bward = 0;
	if (key == KEY_LEAVE)
		map->esc = 0;
	if (key == KEY_GOLEFT)
		map->goleft = 0;
	if (key == KEY_GORIGHT)
		map->goright = 0;
	return (1);
}

int	collision(t_info *map, float x, float y)
{
	if (map->map[(int)(y)][(int)(x)] == '.')
		return (0);
	return (1);
}

void	forback(t_info *map, float adds, float addc)
{
	float	addless[2];

	addless[0] = map->px + (-0.15 *(cos ((map->a_ray) * (M_PI / 180))));
	addless[1] = map->py - (-0.15 * (sin ((map->a_ray) * (M_PI / 180))));
	if (map->fward == 1 && collision(map, map->px + addc, map->py - adds) == 0)
	{
		map->px = map->px + addc;
		map->py = map->py - adds;
	}
	if (map->bward == 1 && collision(map, addless[0], addless[1]) == 0)
	{
		map->px = map->px + (-0.15 * (cos((map->a_ray) * (M_PI / 180))));
		map->py = map->py - (-0.15 * (sin((map->a_ray) * (M_PI / 180))));
	}
	if (map->goleft == 1 && collision(map, map->px - adds, map->py - addc) == 0)
	{
		map->px = map->px - adds;
		map->py = map->py - addc;
	}
	if (map->goright == 1 && collision(map, map->px + adds, map->py + addc)
		== 0)
	{
		map->px = map->px + adds;
		map->py = map->py + addc;
	}
}

void	event(t_info *map)
{
	float	adds;
	float	addc;

	adds = ((float)0.15 * (sin((map->a_ray) * (M_PI / 180))));
	addc = ((float)0.15 * (cos((map->a_ray) * (M_PI / 180))));
	if (map->turnleft == 1)
		map->a_ray += 1.3;
	if (map->turnright == 1)
		map->a_ray -= 1.3;
	forback(map, adds, addc);
	if (map->esc == 1)
		free_map(map);
	if (map->esc == 1)
		exit(0);
}
