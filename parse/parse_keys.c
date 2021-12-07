/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:10:58 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/20 04:55:23 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	search_keys(char *line)
{
	if ((line[0] == 'C') \
	|| (line[0] == 'W' && line[1] == 'E') \
	|| (line[0] == 'E' && line[1] == 'A') \
	|| (line[0] == 'F') \
	|| (line[0] == 'S' && line[1] == 'O') \
	|| (line[0] == 'N' && line[1] == 'O') \
	|| (line[0] == '\0'))
		return (0);
	return (error(19));
}

int	check_info_here(t_info *map)
{
	if (map->r_f == -1 \
			|| map->g_f == -1 || map->b_f == -1 \
			|| map->r_c == -1 || map->g_c == -1 \
			|| map->b_c == -1)
		return (1);
	if (map->pt_no_t == NULL \
			|| map->pt_so_t == NULL \
			|| map->pt_we_t == NULL \
			|| map->pt_ea_t == NULL )
		return (1);
	return (0);
}

int	found_extention(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == 'm' && line[len - 2] == 'p' && \
			line[len - 3] == 'x' && line[len - 4] == '.')
		return (0);
	else
		return (1);
	return (0);
}

void	init_struct(t_info *map, char **av)
{
	map->pass = 0;
	map->start_map = 0;
	map->res_x = -1;
	map->res_y = -1;
	map->px = 0;
	map->py = 0;
	map->r_f = -1;
	map->g_f = -1;
	map->b_f = -1;
	map->r_c = -1;
	map->g_c = -1;
	map->b_c = -1;
	map->line_size = 0;
	map->line_compt = 0;
	map->pt_no_t = NULL;
	map->pt_so_t = NULL;
	map->pt_we_t = NULL;
	map->pt_ea_t = NULL;
	map->filename = NULL;
	map->filename = av[1];
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
