/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:27:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 19:10:16 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' \
			|| str[i - 3] != 'c' || str[i - 4] != '.')
	{
		ft_putstr("-Wrong map extention");
		exit (0);
	}
	return (0);
}

int	parse(char **av, t_info *map)
{
	int		i;

	i = 0;
	if (check_filename(av[1]) == 1)
		return (1);
	if (start_parse(map, av, 1) == 1)
		return (1);
	if (i == 0)
	{
		if (parse_map(map) == 1)
			return (1);
	}
	return (0);
}

void	free_map(t_info *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free_line(map->map[i]);
		i++;
	}
	mlx_destroy_image(map->img.mlx, map->img.img);
	mlx_destroy_window(map->img.mlx, map->img.mlx_win);
}

int	free_p(t_info *map)
{
	free(map->pt_ea_t);
	free(map->pt_so_t);
	free(map->pt_we_t);
	free(map->pt_no_t);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	map;
	int		i;

	i = 0;
	(void)av;
	if (ac == 1)
		return (error(15));
	if (parse(av, &map) == 1)
	{
		free_p(&map);
		return (1);
	}
	map.px += 0.5;
	map.py += 0.5;
	if (init_imp(&map) == 1)
	{
		error(16);
		free_map(&map);
		exit (0);
	}
	if (graph(&map) == 0)
		return (0);
	return (0);
}
