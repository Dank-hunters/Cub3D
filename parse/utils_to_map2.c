/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:26:16 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/21 20:04:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	found_start_map(t_info *map)
{
	char	*line;
	int		fd;
	int		compt;
	int		ret;

	line = NULL;
	ret = 1;
	compt = 0;
	fd = open(map->filename, O_RDONLY);
	while (compt <= map->start_map && ret == 1)
	{
		ret = gnl(fd, &line);
		compt++;
		if (line[0] == '\0')
			map->start_map++;
		if (compt <= map->start_map)
			free_line(line);
	}
	if (line[0] == '1' || line[0] == ' ')
		return (take_info_needed(map, fd, line));
	close(fd);
	free_line(line);
	return (rt(0, "no map found", map));
}

void	cut(int fd, char *line, t_info *map)
{
	int	ret;
	int	i;

	i = 1;
	ret = 1;
	while (ret == 1 && i < map->line_compt)
	{
		ret = gnl(fd, &line);
		map->map[i] = ft_join(line, map, 1);
		free_line(line);
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
		return (rt(0, "-Erreur 1 de malloc", map));
	fd = open(map->filename, O_RDONLY);
	while (map->start_map >= 0 && ret == 1)
	{
		ret = gnl(fd, &line);
		map->start_map--;
		if (map->start_map >= 0)
			free_line(line);
	}
	ft_putnbr(map->line_compt);
	map->map[0] = ft_join(line, map, 1);
	if (map->map[0] == NULL)
		return (rt(0, "-Erreur de malloc", map));
	cut(fd, line, map);
	free_line(line);
	close(fd);
	return (0);
}
