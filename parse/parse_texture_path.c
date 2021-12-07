/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:21:02 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/20 04:55:35 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_no_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (error(1));
	i = skip_space(line, i);
	if (map->pt_no_t == NULL)
		map->pt_no_t = ft_join(line + i, map, 0);
	else
		return (error(1));
	if (map->pt_no_t == NULL)
		return (error(6));
	if (found_extention(line) == 1)
		return (error(1));
	if (line != NULL)
		free(line);
	line = NULL;
	return (0);
}

int	parse_so_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (error(1));
	i = skip_space(line, i);
	if (map->pt_so_t == NULL)
		map->pt_so_t = ft_join(line + i, map, 0);
	else
		return (error(1));
	if (map->pt_so_t == NULL)
		return (error(6));
	if (found_extention(line) == 1)
		return (error(1));
	if (line != NULL)
		free(line);
	line = NULL;
	return (0);
}

int	parse_we_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (error(1));
	i = skip_space(line, i);
	if (map->pt_we_t == NULL)
		map->pt_we_t = ft_join(line + i, map, 0);
	else
		return (error(1));
	if (map->pt_we_t == NULL)
		return (error(6));
	if (found_extention(line) == 1)
		return (error(1));
	if (line != NULL)
		free(line);
	line = NULL;
	return (0);
}

int	parse_ea_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (error(1));
	i = skip_space(line, i);
	if (map->pt_ea_t == NULL)
		map->pt_ea_t = ft_join(line + i, map, 0);
	else
		return (error(1));
	if (map->pt_ea_t == NULL)
		return (error(6));
	if (found_extention(line) == 1)
		return (error(1));
	if (line != NULL)
		free(line);
	line = NULL;
	return (0);
}
