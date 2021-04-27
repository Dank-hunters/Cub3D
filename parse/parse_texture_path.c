/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:21:02 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/27 15:16:49 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_no_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before NO texture aces path ", map));
	i = skip_space(line, i);
	if (map->path_to_no_texture == NULL)
		map->path_to_no_texture = scopy(line, i);
//	else 
//		return (rt(0, "the NO texture path line is duplicate", map));
	if (map->path_to_no_texture == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the NO texture", map));
	return (0);
}

int	parse_so_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before SO texture aces path ", map));
	i = skip_space(line, i);
	if (map->path_to_so_texture == NULL)
		map->path_to_so_texture = scopy(line, i);
//	else 
//		return (rt(0, "the SO texture path line is duplicate", map));
	if (map->path_to_so_texture == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the SO texture", map));
	return (0);
}

int	parse_we_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before WE texture aces path ", map));
	i = skip_space(line, i);
	if (map->path_to_we_texture == NULL)
		map->path_to_we_texture = scopy(line, i);
//	else 
//		return (rt(0, "the WE texture path line is duplicate", map));
	if (map->path_to_we_texture == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the WE texture", map));
	return (0);
}

int	parse_ea_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before EA texture aces path ", map));
	i = skip_space(line, i);
	if (map->path_to_ea_texture == NULL)
		map->path_to_ea_texture = scopy(line, i);
//	else 
//		return (rt(0, "the EA texture path line is duplicate", map));
	if (map->path_to_ea_texture == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the EA texture", map));
	return (0);
}

int	parse_sprite_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before sprite texture aces path ", map));
	i = skip_space(line, i);
	if (map->path_to_sprite_texture == NULL)
		map->path_to_sprite_texture = scopy(line, i);
//	else 
//		return (rt(0, "the sprite texture path line is duplicate", map));
	if (map->path_to_sprite_texture == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the sprite texture", map));
	return (0);
}
