/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:10:12 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/20 16:06:39 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	take_info_needed(t_info *map, int fd, char *line)
{
	int	ret;

	ret = 1;
	map->line_compt = 1;
	map->line_size = ft_strlen(line);
	map->line_compt = 0;
	while (ret == 1)
	{
		if (ft_parse_char(line) == 1)
		{
			free_line(line);
			return (rt(0, "wrong caracteres in map", map));
		}
		ret = gnl(fd, &line);
		map->line_compt++;
		if (ft_strlen(line) > map->line_size)
			map->line_size = ft_strlen(line);
	}
	free_line(line);
	close(fd);
	return (0);
}

int	ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_charchr(char c)
{
	int			i;
	static char	*chr = " 012NSEW";

	i = 0;
	while (chr[i])
	{
		if (chr[i] == c || c == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_char(char *line)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (line[i])
	{
		if (ft_charchr(line[i]) == 0)
			i++;
		else
			return (1);
	}
	free_line(line);
	return (0);
}

char	*ft_join(char *line, t_info *map)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (map->line_size + 1));
	if (dest == NULL)
		return (NULL);
	while (line[i])
	{
		dest[i] = line[i];
		i++;
	}
	while (ft_strlen(line) != 0 && i < map->line_size)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
