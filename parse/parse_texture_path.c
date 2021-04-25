/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:21:02 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/25 16:51:07 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_no_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before NO texture aces path "));
	i = skip_space(line, i);
	map->path_to_no_texture = scopy(line, i);
	if (map->path_to_no_texture == NULL)
		return (rt(0, "-In malloc"));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the NO texture"));
	return (0);
}

int	parse_so_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before SO texture aces path "));
	i = skip_space(line, i);
	map->path_to_so_texture = scopy(line, i);
	if (map->path_to_so_texture == NULL)
		return (rt(0, "-In malloc"));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the SO texture"));
	return (0);
}

int	parse_we_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before WE texture aces path "));
	i = skip_space(line, i);
	map->path_to_we_texture = scopy(line, i);
	if (map->path_to_we_texture == NULL)
		return (rt(0, "-In malloc"));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the WE texture"));
	return (0);
}

int	parse_ea_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before EA texture aces path "));
	i = skip_space(line, i);
	map->path_to_ea_texture = scopy(line, i);
	if (map->path_to_ea_texture == NULL)
		return (rt(0, "-In malloc"));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the EA texture"));
	return (0);
}

int	parse_sprite_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before sprite texture aces path "));
	i = skip_space(line, i);
	map->path_to_sprite_texture = scopy(line, i);
	if (map->path_to_sprite_texture == NULL)
		return (rt(0, "-In malloc"));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the sprite texture"));
	return (0);
}
