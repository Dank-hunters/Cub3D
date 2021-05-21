/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/07 17:42:12 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	skip_num(char *str, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	take_size(char *str, int start)
{
	int	size;

	size = 0;
	while (str[start] && (str[start] >= '0' && str[start] <= '9'))
	{
		size = size * 10 + str[start] - '0';
		start++;
		if (size >= 10000)
			return (-1);
	}
	return (size);
}

void	init_struct(t_info *map)
{
	map->pass = 0;
	map->res_x = -1;
	map->res_y = -1;
	map->r_floor = -1;
	map->g_floor = -1;
	map->b_floor = -1;
	map->r_ceiling = -1;
	map->g_ceiling = -1;
	map->b_ceiling = -1;
	map->line_size = 0;
	map->line_compt = 0;
	map->path_to_no_texture = NULL;
	map->path_to_so_texture = NULL;
	map->path_to_we_texture = NULL;
	map->path_to_ea_texture = NULL;
	map->path_to_sprite_texture = NULL;
	map->filename = NULL;
}

int	search_keys(char *line, t_info *map)
{
	if ((line[0] == 'R') \
	|| (line[0] == 'C') \
	|| (line[0] == 'W' && line[1] == 'E') \
	|| (line[0] == 'E' && line[1] == 'A') \
	|| (line[0] == 'S') \
	|| (line[0] == 'F') \
	|| (line[0] == 'S' && line[1] == 'O') \
	|| (line[0] == 'N' && line[1] == 'O') \
	|| (line[0] == '\0'))
		return (0);
	return (rt(0, /*Map parsing can't start cause all necessary information aren't acquired yet*/
			"- information invalide or end of description but missing infos"\
			, map));
}
