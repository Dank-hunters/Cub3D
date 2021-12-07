/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minolib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:47:32 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/21 18:59:15 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	*free_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

void	errore(t_info *map)
{
	map->not_close = 6;
	ft_putstr("-Error\nThe map is not closes");
	exit(0);
}

int	test_map(t_info *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < map->line_compt)
	{
		if (map->map[i][0] == '\0')
		{
			while (y < map->line_compt)
			{
				free_line(map->map[y]);
				y++;
			}
			free(map->map);
			return (error(7));
		}
		i++;
	}
	return (0);
}
