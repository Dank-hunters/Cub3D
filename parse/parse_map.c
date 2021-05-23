/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:45 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/23 19:21:40 by cguiot           ###   ########lyon.fr   */
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

int init_tab_map(t_info *map)
{
	int fd;
	int ret;
	int i;
	char *line;

	line = NULL;
	i = 0;
	ret = 1;
	map->map = malloc(sizeof(char *) * (map->line_compt + 1));
	fd = open(map->filename, O_RDONLY);
	while (map->start_map >= 0 && ret == 1)
	{
		ret = gnl(fd, &line);
		map->start_map--;
		if (map->start_map >= 0)
			free_line(line);
	}
	map->map[i++] = ft_join(line, map);
	if (map->map[i] == NULL)
		return (rt(0, "-Erreur de malloc", map));
	free_line(line);
	while (ret == 1 && i < map->line_compt)
	{
		ret = gnl(fd, &line);
		map->map[i] = ft_join(line, map);
		free_line(line);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (0);
}

int	ft_found_pos(t_info *map)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	x = 0;
	map->pos_y = 0;
	map->pos_x = 0;
	while (map->map[y] != 0)
	{
		//	dprintf(1, "||%s||\n", map->map[y]);
		while(map->map[y][x])
		{
			if (map->map[y][x] == 'N' \
					|| map->map[y][x] == 'S' \
					|| map->map[y][x] == 'E' \
					|| map->map[y][x] == 'W')
			{
				i++;
				map->pos_x = x + 0.5;
				map->pos_y = y + 0.5;
				map->view_d = map->map[y][x];
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
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (rt(0, "there are no player", map));
	}
	if (i >= 2)
	{
		while(y < map->line_compt)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (rt(0, "there are more than 1 spawn point", map));
	}
	return (0);
}

int    fill_flood_map(t_info *map, int y, int x)
{
	if (y < 0 || x < 0 || y > map->line_compt - 1 || \
			x > map->line_size - 1)
		return(rt(666, \
			"-Error\n The map is not close.\n", map));
	if (ft_ischar("|.$#", map->map[y][x]))
		return (0);
	if (map->map[y][x] == '1')
	{
		map->map[y][x] = '|';
		return (0);
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
	return (0);
}

int test_map(t_info *map)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i < map->line_compt)
	{
		//	dprintf(1, "%s\n", map->map[i]);
		if (map->map[i][0] == '\0')
		{
			while(y < map->line_compt)
			{
				free_line(map->map[y]);
				y++;
			}
			free(map->map);
			return (rt(0, "-Empty line in middle or a the end of map", map));
		}
		i++;
	}
	return (0);
}

int parse_map(t_info *map)
{
	int i = 0;
	map->tofree = 0;
	if (found_start_map(map) == 1)
		return (1);
	init_tab_map(map);
	if (test_map(map) == 1)
		return (1);
	if (ft_found_pos(map) == 1)
		return (1);
	//	dprintf(1, "mon joeur : %i, %i\n", map->pos_y, map->pos_x);
	fill_flood_map(map, map->pos_y, map->pos_x);
	if (map->tofree == 2)
	{
		while (i < map->line_compt)
		{
			free_line(map->map[i]);
			i++;
		}
		free(map->map);
		return (1);
	}
	/*	while (map->map[i] != 0)
		{
		dprintf(1, "ma map : %s\n", map->map[i]);
		i++;
		}
		dprintf(1, "ma map : %s\n", map->map[i]);*/
	dprintf(1, "lets go parse");
	return (0);
}
