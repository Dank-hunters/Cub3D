/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:27:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/25 20:58:50 by cguiot           ###   ########lyon.fr   */
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

/*void	test()
{
	t_map *cub;

	dprintf(1, "cub->");


}*/

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
			while(map.map[i])
		{	
			dprintf(1, "%s\n", map.map[i]);
			i++;
		}
		//dprintf(1, "\nx = %f, y = %f, taille ligne : %i, nombre ligne : %i, res x: %i, res y %i\n",	cub.pos_x, cub.pos_y, map.line_size, map.line_compt, map.res_x, map.res_y);
	i = 0;
	graph(&map);
//	test();
	return (0);
}
