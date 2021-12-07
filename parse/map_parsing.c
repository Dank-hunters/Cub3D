/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:21:38 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 19:10:24 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*next_found(char *line, t_info *map, int fd)
{
	int	ret;

	ret = 1;
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		map->start_map++;
		if (line[0] == '\0')
		{
			if (line != NULL)
			{
				free(line);
				line = NULL;
			}
		}
		if (line != NULL && line[0] != '\0')
			break ;
	}
	return (line);
}

int	found_start_map(t_info *map)
{
	char	*line;
	int		fd;
	int		compt;
	int		ret;

	ret = 1;
	compt = 0;
	fd = open(map->filename, O_RDONLY);
	while (compt <= map->start_map && ret == 1)
	{
		ret = get_next_line(fd, &line);
		compt++;
		if (compt <= map->start_map)
			line = free_line(line);
	}
	if (line != NULL && line[0] == '\0')
		line = next_found(line, map, fd);
	if (line && (line[0] == '1' || line[0] == ' ' || line[0] == 'N' || \
			   	line[0] == 'S' || line[0] == 'E' || line[0] == 'W' || \
				line[0] == '0'))
		return (take_info_needed(map, fd, line));
	close(fd);
	if (line)
		free(line);
	return (error(5));
}

int	take_info_needed(t_info *map, int fd, char *line)
{
	int	ret;

	ret = 1;
	map->line_size = ft_strlen(line);
	map->line_compt = 0;
	while (ret == 1)
	{
		if (ft_parse_char(line) == 1)
		{
			if (line != NULL)
			{
				free(line);
				line = NULL;
			}
			return (error(11));
		}
		ret = get_next_line(fd, &line);
		map->line_compt++;
		if (ft_strlen(line) > map->line_size)
			map->line_size = ft_strlen(line);
	}
	free_line(line);
	close(fd);
	return (0);
}

void	cut(int fd, char *line, t_info *map)
{
	int	ret;
	int	i;

	i = 1;
	ret = 1;
	while (ret == 1 && i < map->line_compt)
	{
		ret = get_next_line(fd, &line);
		map->map[i] = ft_join(line, map, 1);
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		i++;
	}
	map->map[i] = NULL;
}

int	init_tab_map(t_info *map)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	ret = 1;
	map->map = malloc(sizeof(char *) * (map->line_compt + 1));
	if (map->map == NULL)
		return (error(6));
	fd = open(map->filename, O_RDONLY);
	while (map->start_map >= 0 && ret == 1)
	{
		ret = get_next_line(fd, &line);
		map->start_map--;
		if (map->start_map >= 0)
			free_line(line);
	}
	map->map[0] = ft_join(line, map, 1);
	if (map->map[0] == NULL)
		return (error(6));
	cut(fd, line, map);
	free_line(line);
	close(fd);
	return (0);
}
