/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/24 17:35:46 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int skip_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int skip_num(char *str, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int take_size(char *str, int start)
{
	int	size;

	size = 0;
	while (str[start] && (str[start] >= '0' && str[start] <= '9'))
	{
		size = size * 10 + str[start] - '0';
		start++;
	}
//	dprintf(1, "\n||||||%i||||\n", size);
	return (size);
}

void init_struct(t_info *map)
{
	map->res_x = -1;
	map->res_y = -1;
	map->r_floor = -1;
	map->g_floor = -1;
	map->b_floor = -1;

}

int search_keys(char *line)
{
	if ((line[0]  == 'R') \
		|| (line[0] == 'C') \
			|| (line[0]  == 'W' && line[1] == 'E') \
			|| (line[0]  == 'E' && line[1] == 'A') \
			|| (line[0]  == 'S') \
			|| (line[0] == 'F') \
			|| (line[0]  == 'S' && line[1] == 'O') \
			|| (line[0]  == 'N' && line[1] == 'O') \
			|| (line[0] == '\0'))
		return (0);
	return (1);




}
