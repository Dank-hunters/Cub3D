/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:48:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/25 17:21:35 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_line_part3(char *line, int num_line, t_info *map)
{
	if (line[0]  == 'N' && line[1] == 'O')
	{
		if (parse_no_texture(line, map, 2) == 1)
			return (1);
	}
	else if (line[0]  == 'S' && line[1] == 'O')
	{if (parse_so_texture(line, map, 2) == 1)
			return (1);
	}
	else if (line[0]  == 'W' && line[1] == 'E')
	{
		if (parse_we_texture(line, map, 2) == 1)
			return (1);
	}
	else if (line[0]  == 'E' && line[1] == 'A')
	{
		if (parse_ea_texture(line, map, 2) == 1)
			return (1);
	}
	else if (line[0]  == 'S')
	{
		if (parse_sprite_texture(line, map, 1) == 1)
			return (1);
	}
	return (0);
}
int parse_line_part2(char *line, int num_line, t_info *map)
{
	if (line[0] == '\0')
		return(0);
	else if (line[0] == 'F')
	{
	
		if (parse_floor_color(line, map, 1) == 1)
			return (1);
	}
	else if (line[0] == 'C')
	{
	
		if (parse_ceiling_color(line, map, 1) == 1)
			return(1);
	}
	return (0);
}
int parse_line_part1(char *line, int num_line, t_info *map)
{
	int ret;

	ret = 0;
	if (line[0]  == 'R')
		if (parse_res(line, map, 1) != 0)
			return (1);
	return (0);
}

int parse_line(char *line, int num_line, t_info *map)
{
	if (parse_line_part1(line, num_line, map) == 1)
		return (1);
	else if (parse_line_part2(line, num_line, map) == 1)
		return (1);
	else if (parse_line_part3(line, num_line, map) == 1)
		return (1);
	else if (search_keys(line) == 1)
		return (1);
	return (0);
}

int start_parse(char **av)
{
	t_info map;
	char *line;
	int fd;
	int ret;
	int num_line;

	init_struct(&map);
	num_line = 0;
	ret = 1;
	fd = open(av[1], O_RDONLY);
	while (ret == 1)
	{
		ret = gnl(fd, &line);
		num_line++;
		if (parse_line(line, num_line, &map) == 1)
			return (rt(num_line, "- At line : "));
	}
	if (map.pass < 8 || check_info_here(&map) == 1)
		return(rt(0, "there missing an info line"));
	if (map.pass > 8)
		return(rt(0, "there are two line identical"));
	close(fd);
	return(0);
}
