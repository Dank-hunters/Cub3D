/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:48:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/24 17:35:43 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_line_part3(char *line, int num_line, t_info *map)
{
	if (line[0]  == 'N' && line[1] == 'O')
		dprintf(1, "tt%i", parse_NO_texture(line, map, 2));
	else if (line[0]  == 'S' && line[1] == 'O')
		return(0);
	else if (line[0]  == 'W' && line[1] == 'E')
		return (0);
	else if (line[0]  == 'E' && line[1] == 'A')
		return (0);
	else if (line[0]  == 'S')
		return(0);
	return (0);
}
int parse_line_part2(char *line, int num_line, t_info *map)
{
	if (line[0] == '\0')
	{
		dprintf(1, "ligne vide");
		return(0);
	}
	else if (line[0] == 'F')
	{
	
		if (parse_floor_color(line, map, 1) == 1)
		{
			dprintf(1, "nan la ta fait de la merde frerot");
			return(1);
		}
	}
	else if (line[0] == 'C')
	{
	
		if (parse_ceiling_color(line, map, 1) == 1)
		{
		dprintf(1, "petite erreur dans les ceiling color");
		return(1);
		}
	}
	return (0);
}
int parse_line_part1(char *line, int num_line, t_info *map)
{
	int ret;

	ret = 0;
	if (line[0]  == 'R')
	{
	
		if (parse_res(line, map, 1) != 0)
		{
			dprintf(1, "erreur dans la resolution ");  //print une vrai erreur plus explicite
			return (1);
		}
		else 
		{
		//	dprintf(1, "res : %i |  %i", map->res_x, map->res_y);
			return (0);
		}
	}
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
			return (1); 	//	return (error(num_line));
		dprintf(1, "L%i |%s\n", num_line, line);
	}
	close(fd);
	return(0);
}
