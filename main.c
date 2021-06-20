/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:27:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/20 16:07:27 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_filename(char *str, t_info *map)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i - 4] != '.')
		return (rt(0, "-Wrong map extention", map));
	return (0);
}

int	parse(char **av, t_info *map)
{
	int		i;
	
	i = 0;
	if (check_filename(av[1], map) == 1)
		return (1);
	if (start_parse(av, map))
		return (1);
	if (i == 0)
	{
		if (parse_map(map) == 1)
			return (1);
	}
	return (0);
}

//int get_xpm(t_info *map)

int	init_imp(t_info *map)
{
	int i;
	i = 0;

//	if (init_text(t_info *map) >= 1)
//		clean_and_quit()

	map->map[(int)map->py][(int)map->px] = '.';
	while (map->map[i])
	{	
		dprintf(1, "%s\n", map->map[i]);
		i++;
	}
	initss(map);
	map->img.mlx = mlx_init();
	map->img.mlx_win = mlx_new_window(map->img.mlx, map->res_x, map->res_y, "Hello world!");
	if (map->img.mlx_win == NULL)
		dprintf(1, "win creation failled");
	map->img.img = mlx_new_image(map->img.mlx, map->res_x, map->res_y);
	if (map->img.img == NULL)
		dprintf(1, "img creation failled");
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bpp, &map->img.line_len,
								&map->img.endian);
	if (map->img.addr == NULL)
		dprintf(1, "img creation failled");
	//////////////////////////////////////////////////////////////////
	file_to_img(map);
	if (init_text(map) >= 1)
		return (1);
	return (0);
	}

void	free_map(t_info *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
	//	free_line(map->map[i]);
		i++;
	}
	mlx_destroy_image(map->img.mlx, map->img.img);
	mlx_destroy_window(map->img.mlx, map->img.mlx_win);
}

int main(int ac, char **av)
{
	t_info	map;

	int i = 0;
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	if (parse(av, &map) == 1)
		return (1);
	dprintf(1, "\n");
	i = 0;
	//dprintf(1, "%s", map.pt_no_t);
	if (init_imp(&map) == 1)
		free_map(&map);
	if (graph(&map) == 0)
		return(0);
	return (0);
}
