/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:45 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/21 16:52:13 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int found_start_map(t_info *map)
{
	char *line;
	int fd;
	int compt;
	int ret;

	line = NULL;
	ret = 1;
	compt = 0;
	fd = open(map->filename, O_RDONLY);
	while (compt <=	map->start_map && ret == 1)
	{
		ret = gnl(fd, &line);
		compt++;
		if (line[0] == '\0')
			map->start_map++;
		if (compt <= map->start_map)
			free_line(line);
	}
	//	dprintf(1, "%s", line);
	if (line[0] == '1' || line[0] == ' ')
		return(take_info_needed(map, fd, line));
	close (fd);
	free_line(line);
	return(rt(0, "no map found", map));
}

int init_tab_map(t_info *map, t_map *cub)
{
	int fd;
	int ret;
	int i;
	char *line;

	line = NULL;
	i = 0;
	ret = 1;
	cub->map = malloc(sizeof(char *) * (map->line_compt + 1));
	fd = open(map->filename, O_RDONLY);
	while (map->start_map >= 0 && ret == 1)
	{
		ret = gnl(fd, &line);
		map->start_map--;
		if (map->start_map >= 0)
			free_line(line);
	}
	cub->map[i++] = ft_join(line, map);
	if (cub->map[i] == NULL)
		return (rt(0, "-Erreur de malloc", map));
	free_line(line);
	while (ret == 1 && i < map->line_compt)
	{
		ret = gnl(fd, &line);
		cub->map[i] = ft_join(line, map);
		free_line(line);
		i++;
	}
	cub->map[i] = NULL;
	close(fd);
	return (0);
}

int	ft_found_pos(t_map *cub, t_info *map)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	x = 0;
	cub->pos_y = 0;
	cub->pos_x = 0;
	while (cub->map[y] != 0)
	{
		//	dprintf(1, "||%s||\n", cub->map[y]);
		while(cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' \
					|| cub->map[y][x] == 'S' \
					|| cub->map[y][x] == 'E' \
					|| cub->map[y][x] == 'W')
			{
				i++;
				cub->pos_x = x;
				cub->pos_y = y;
				cub->view_d = cub->map[y][x];
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	if (i == 0)
	{
		while(y < map->line_compt)
		{
			free_line(cub->map[y]);
			y++;
		}
		free(cub->map);
		return (rt(0, "there are no player", map));
	}
	if (i >= 2)
	{
		while(y < map->line_compt)
		{
			free_line(cub->map[y]);
			y++;
		}
		free(cub->map);
		return (rt(0, "there are more than 1 spawn point", map));
	}
	return (0);
}

int    fill_flood_map(t_map *cub, t_info *map, int y, int x)
{
	if (y < 0 || x < 0 || y > map->line_compt - 1 || \
			x > map->line_size - 1)
		return(rt(666, \
			"-Error\n The map is not close.\n", map));
	if (ft_ischar("|.$#", cub->map[y][x]))
		return (0);
	if (cub->map[y][x] == '1')
	{
		cub->map[y][x] = '|';
		return (0);
	}
	if (cub->map[y][x] == '0')
		cub->map[y][x] = '.';
	if (cub->map[y][x] == '2')
		cub->map[y][x] = '$';
	if (cub->map[y][x] == '3')
		cub->map[y][x] = '#';
	fill_flood_map(cub, map, y - 1, x);
	fill_flood_map(cub, map, y + 1, x);
	fill_flood_map(cub, map, y, x - 1);
	fill_flood_map(cub, map, y, x + 1);
	return (0);
}

int test_map(t_info *map, t_map *cub)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i < map->line_compt)
	{
		//	dprintf(1, "%s\n", cub->map[i]);
		if (cub->map[i][0] == '\0')
		{
			while(y < map->line_compt)
			{
				free_line(cub->map[y]);
				y++;
			}
			free(cub->map);
			return (rt(0, "-Empty line in middle or a the end of map", map));
		}
		i++;
	}
	return (0);
}

int parse_map(t_info *map, t_map *cub)
{
	int i = 0;
	map->tofree = 0;
	if (found_start_map(map) == 1)
		return (1);
	init_tab_map(map, cub);
	if (test_map(map, cub) == 1)
		return (1);
	if (ft_found_pos(cub, map) == 1)
		return (1);
	//	dprintf(1, "mon joeur : %i, %i\n", cub->pos_y, cub->pos_x);
	fill_flood_map(cub, map, cub->pos_y, cub->pos_x);
	if (map->tofree == 2)
	{
		while (i < map->line_compt)
		{
			free_line(cub->map[i]);
			i++;
		}
		free(cub->map);
		return (1);
	}
	/*	while (cub->map[i] != 0)
		{
		dprintf(1, "ma map : %s\n", cub->map[i]);
		i++;
		}
		dprintf(1, "ma map : %s\n", cub->map[i]);*/
	dprintf(1, "lets go parse");
	return (0);
}
