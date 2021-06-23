/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/22 19:55:04 by cguiot           ###   ########lyon.fr   */
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

void	init_struct(t_info *map, char **av)
{
	map->pass = 0;
	map->res_x = -1;
	map->res_y = -1;
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
	map->pt_sp_t = NULL;
	map->py = 0;
	map->px = 0;
	map->filename = av[1];
}

int	search_keys(char *line, t_info *map)
{
	if ((line[0] == 'C') \
	|| (line[0] == 'W' && line[1] == 'E') \
	|| (line[0] == 'E' && line[1] == 'A') \
	|| (line[0] == 'F') \
	|| (line[0] == 'S' && line[1] == 'O') \
	|| (line[0] == 'N' && line[1] == 'O') \
	|| (line[0] == '\0'))
		return (0);
	return (rt(0,
			"- information invalide or end of description but missing infos" \
			, map));
}
