/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:27:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/12 21:13:56 by cguiot           ###   ########lyon.fr   */
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

void	init_imp(t_info *map)
{
	int i;
	i = 0;
map->map[(int)map->pos_y][(int)map->pos_x] = '.';
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
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length,
								&map->img.endian);
	if (map->img.addr == NULL)
		dprintf(1, "img creation failled");
	//////////////////////////////////////////////////////////////////
		map->xpm[0].img = mlx_xpm_file_to_image(map->img.mlx, map->path_to_no_texture, &map->xpm[0].width, &map->xpm[0].height);
    if (map->xpm[0].img != NULL)
	{
        map->xpm[0].addr = (int *)mlx_get_data_addr(map->xpm[0].img, &map->xpm[0].bits_per_pixel, &map->xpm[0].line_length,
					&map->xpm[0].endian);
	}
	else
		dprintf(1, "ta mere");
	if  (map->xpm[0].addr == NULL)
       {
           dprintf(1, "ta mere ");
           exit(0);
       }
}
int main(int ac, char **av)
{
	t_info	map;
	//char *lol;

	int i = 0;
//	lol = malloc(sizeof(char) * 5);
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	if (parse(av, &map) == 1)
		return (1);
	dprintf(1, "\n");
		//dprintf(1, "\nx = %f, y = %f, taille ligne : %i, nombre ligne : %i, res x: %i, res y %i\n",	cub.pos_x, cub.pos_y, map.line_size, map.line_compt, map.res_x, map.res_y);
	i = 0;
	dprintf(1, "les path: \nNO : %s,\n So: %s,\n EA : %s,\n WE: %s,\n SP :%s", map.path_to_no_texture, map.path_to_so_texture, map.path_to_ea_texture, map.path_to_we_texture, map.path_to_sprite_texture);
	init_imp(&map);
	if (graph(&map) == 0)
		return(0);
	return (0);
}