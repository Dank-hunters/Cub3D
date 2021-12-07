/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:31:06 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 18:40:56 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_sec(t_info *map, char *line)
{
	if (line[0] == '\0' && map->start_map == 1)
		return (error(20));
	if (line && line[0] == 'C')
	{
		map->pass++;
		if (parse_ceiling_color(line, map, 1) == 1)
			return (error(3));
	}
	if (map->r_f > 255)
		return (error(18));
	else if (map->g_f > 255)
		return (error(18));
	else if (map->b_f > 255)
		return (error(18));
	else if (map->r_c > 255)
		return (error(18));
	else if (map->g_c > 255)
		return (error(18));
	else if (map->b_c > 255 )
		return (error(18));
	else
		return (0);
	return (0);
}

int	parse_first(char *line, t_info *map)
{
	if (line[0] == '\0' && line && map->start_map > 1 )
	{
		free(line);
		line = NULL;
		return (0);
	}
	else if (search_keys(line) != 0)
		return (1);
	else if (line[0] == 'N' && line[1] == 'O')
		return (parse_no_texture(line, map, 2));
	else if (line[0] == 'S' && line[1] == 'O')
		return (parse_so_texture(line, map, 2));
	else if (line[0] == 'W' && line[1] == 'E')
		return (parse_we_texture(line, map, 2));
	else if (line[0] == 'E' && line[1] == 'A')
		return (parse_ea_texture(line, map, 2));
	if (line[0] == 'F')
	{
		map->pass++;
		if (parse_floor_color(line, map, 1) == 1)
			return (error(2));
	}
	else
		return (parse_sec(map, line));
	return (0);
}

int	start_parse(t_info *map, char **av, int ret)
{
	int		fd;
	char	*line;

	init_struct(map, av);
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (ret == 1 && map->pass != 6)
	{
		ret = get_next_line(fd, &line);
		map->start_map++;
		if (parse_first(line, map) > 0)
		{
			if (line != NULL)
			{
				free(line);
				line = NULL;
				return (1);
			}
		}
	}
	close(fd);
	if (map->pass < 6 || check_info_here(map) == 1)
		return (error(4));
	return (0);
}

int	parse_map(t_info *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	map->tofree = 0;
	if (found_start_map(map) == 1)
		return (1);
	init_tab_map(map);
	if (test_map(map) == 1)
		return (1);
	if (ft_found_pos(map, i, y) == 1)
		return (1);
	if (fill_flood_map(map, map->px, map->py) == 0)
	{
		while (i < map->line_compt)
		{
			free_line(map->map[i]);
			i++;
		}
		free(map->map);
		return (error(10));
	}
	return (0);
}
