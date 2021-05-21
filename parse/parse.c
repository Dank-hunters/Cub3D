/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:48:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/15 16:06:21 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_line_part3(char *line, t_info *map)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (parse_no_texture(line, map, 2) == 1);
	else if (line[0] == 'S' && line[1] == 'O')
		return (parse_so_texture(line, map, 2) == 1);
	else if (line[0] == 'W' && line[1] == 'E')
		return (parse_we_texture(line, map, 2) == 1);
	else if (line[0] == 'E' && line[1] == 'A')
		return (parse_ea_texture(line, map, 2) == 1);
	else if (line[0] == 'S')
		return (parse_sprite_texture(line, map, 1) == 1);
	return (0);
}

int	parse_line_part2(char *line, t_info *map)
{
	if (line && line[0] == '\0')
		return (0);
	if (line[0] == 'F')
	{
		if (parse_floor_color(line, map, 1) == 1)
			return (1);
	}
	else if (line[0] == 'C')
	{
		if (parse_ceiling_color(line, map, 1) == 1)
			return (1);
	}
	return (0);
}

int	parse_line_part1(char *line, t_info *map)
{
	int	ret;

	ret = 0;
	if (line[0] == '\0' && map->pass == 0)
		return (rt(0, "- File start with empty line", map));
	if (line[0] == 'R')
		if (parse_res(line, map, 1) != 0)
			return (1);
	return (0);
}

int	parse_line(char *line, t_info *map)
{
	if (parse_line_part1(line, map) == 1)
			return (1);
	else if (parse_line_part2(line, map) == 1)
			return(1);
	else if (parse_line_part3(line, map) == 1)
		return (1);
	else if (search_keys(line, map) == 1)
		return (1);
	if (map->r_floor == -2 || map->r_floor > 255)
		return (rt(-3, "- The R floor interval is too long", map));
	if (map->g_floor == -2 || map->g_floor > 255)
		return (rt(-3, "- The G floor interval is too long", map));
	if (map->b_floor > 255 || map->b_floor == -2)
		return (rt(-3, "- The B floor interval is too long", map));
	if (map->r_ceiling == -2 || map->r_ceiling > 255)
		return (rt(-3, "- The R floor interval is too long", map));
	if (map->g_ceiling == -2 || map->g_ceiling > 255)
		return (rt(-3, "- The G floor interval is too long", map));
	if (map->b_ceiling > 255 || map->b_ceiling == -2)
		return (rt(-3, "- The B floor interval is too long", map));
	return (0);
}

int	start_parse(char **av, t_info *map)
{
	char	*line;
	int		fd;
	int		ret;

	init_struct(map);
	map->start_map = 0;
	ret = 1;
	map->filename = av[1];
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		return (rt(0, "- Wrong file descriptor", map));
	while (ret == 1 && map->pass != 8)
	{
		ret = gnl(fd, &line);
		map->start_map++;
		if (parse_line(line, map) == 1)
		{
			free_line(line);
			return (rt(map->start_map, " at line : ", map));
		}
	}
	close(fd);
	if (map->pass < 8 || check_info_here(map) == 1)
		return (rt(0, "there missing an info line", map));
	return (0);
}
