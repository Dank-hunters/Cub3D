/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minolib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:47:32 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/16 17:45:56 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	n;

	n = nb % 10 + 48;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &n, 1);
}

int	free_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (1);
}

void	error(t_info *map)
{
	map->not_close = 6;
	ft_putstr("-Error\nThe map is not close");
	exit(0);
}

void	fill_flood_map(t_info *map, int y, int x)
{
	if (y < 0 || x < 0 || y > map->line_compt - 1 || \
			x > map->line_size - 1)
		error(map);
	if (ft_ischar("|.$#", map->map[y][x]))
		return ;
	if (map->map[y][x] == '1')
	{
		map->map[y][x] = '|';
		return ;
	}
	if (map->map[y][x] == '0')
		map->map[y][x] = '.';
	if (map->map[y][x] == '2')
		map->map[y][x] = '$';
	if (map->map[y][x] == '3')
		map->map[y][x] = '#';
	fill_flood_map(map, y - 1, x);
	fill_flood_map(map, y + 1, x);
	fill_flood_map(map, y, x - 1);
	fill_flood_map(map, y, x + 1);
}
