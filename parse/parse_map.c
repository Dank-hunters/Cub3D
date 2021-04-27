/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:45 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/27 18:08:12 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		u;

	u = 0;
	i = ft_strlen(src);
	dest = malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (0);
	while (i > u)
	{
		dest[u] = src[u];
		u++;
	}
	dest[u] = '\0';
	return (dest);
}

int skip_empty_line(char *line)
{
	if (line[0] == '\0')
		return (1);
	return (0);
}

int parse_map(char *filename, t_info *map, int fd, int num_line)
{
	int	i;
	int	ret;
	char *line;
	int line_compt;

	(void)num_line;
	line = NULL;
	ret = 1;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (ret == 1 && i <= num_line)
	{
		ret = gnl(fd, &line);
		i++;
		if (skip_empty_line(line) == 1)
			num_line++;
	//	free_line(line);  a free 
	}
	line_compt = 0;
	map->line_size = ft_strlen(line);
	dprintf(1, "%s", line);
	while (ret == 1)
	{
		ret = gnl(fd, &line);
		line_compt++;
		dprintf(1, "\n%i\n", line_compt);
		//free_line(line); a free
	}
	return (0);
}

int	initialisation_map_tab(char *line, int line_compt, t_info *map)
{
	int i;
	char **maps;
	int e;

	e = 0;

//	*maps = NULL;
	i = 0;
	maps = malloc(sizeof(char) * line_compt + 1);
	*maps = malloc(sizeof(char) * map->line_size);
////// ici je doit faire une  nouvelle boucle de gnl pour coprier avec le dup, ma ligne dans mon tableau et fixe le malloc		dprintf(1, "1%s\n", line);
	maps[i] = ft_strdup(line);
	while(line[e])
	{
		dprintf(1, "1%s\n", maps[e]);
		e++;
	}
	return(0);
}
