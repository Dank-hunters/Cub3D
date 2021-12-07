/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:52:08 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 19:10:26 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	skip_num(char *str, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	take_size(char *str, int start)
{
	int	size;

	size = 0;
	while (str[start] && (str[start] >= '0' && str[start] <= '9'))
	{
		size = size * 10 + str[start] - '0';
		start++;
		if (size >= 10000)
			return (-1);
	}
	return (size);
}

int	error2(int index)
{
	if (index == 11)
		ft_putstr("wrong caracteres in map");
	else if (index == 12)
		ft_putstr("win creation failled");
	else if (index == 13)
		ft_putstr("addr img creation failled");
	else if (index == 14)
		ft_putstr("img creation failled");
	else if (index == 15)
		ft_putstr("-Missing map config");
	else if (index == 16)
		ft_putstr("-error in img creation");
	else if (index == 17)
		ft_putstr("path unknow");
	else if (index == 18)
	{
		ft_putstr("interval for R,G,B is 0 < R < 255");
		exit (0);
	}
	else if (index == 19)
		ft_putstr("Missing info to graph/Line start with space");
	else if (index == 20)
		ft_putstr("file start with empty line");
	return (1);
}

int	error(int index)
{
	ft_putstr("Error\n");
	if (index == 1)
		ft_putstr("the texture path got probleme");
	else if (index == 1)
		ft_putstr("the ceiling color got wrong info");
	else if (index == 2)
		ft_putstr("the floor color got wrong info");
	else if (index == 4)
		ft_putstr("there is an info line missing.");
	else if (index == 5)
		ft_putstr("no map found");
	else if (index == 6)
		ft_putstr("malloc crash");
	else if (index == 7)
		ft_putstr("-Empty line in middle or a the end of map");
	else if (index == 8)
		ft_putstr("there are no player");
	else if (index == 9)
		ft_putstr("there are more than 1 spawn point");
	else if (index == 10)
		ft_putstr("The map is not close");
	else if (index > 10)
		error2(index);
	return (1);
}
