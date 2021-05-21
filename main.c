/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:27:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/21 16:36:20 by cguiot           ###   ########lyon.fr   */
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

int	parse(char **av, t_info *map, t_map *cub)
{
	int		i;
	
	i = 0;
	if (check_filename(av[1], map) == 1)
		return (1);
	if (start_parse(av, map))
		return (1);
	if (i == 0)
	{
		if (parse_map(map, cub) == 1)
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_info	map;
	t_map	cub;
//	t_idd	value;
	
	int i = 0;
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	parse(av, &map, &cub);
	
//	init_vars(&value, &map, &cub);
	//if (parse(av, &map, &cub) != 1)
	//{
//		dprintf(1, "\nle path : %s\n", map.path_to_no_texture);
//		dprintf(1, "\n");
	dprintf(1, "\n");
			while(cub.map[i])
		{	
			dprintf(1, "%s\n", cub.map[i]);
			i++;
		}
		//dprintf(1, "\nx = %f, y = %f, taille ligne : %i, nombre ligne : %i, res x: %i, res y %i\n",	cub.pos_x, cub.pos_y, map.line_size, map.line_compt, map.res_x, map.res_y);
	i = 0;
	graph(&map, &cub);
//	dprintf(1, "\n");
	return (0);
}
