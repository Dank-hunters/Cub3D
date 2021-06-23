/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:21:02 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/22 19:54:58 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_no_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before NO taces path ", map));
	i = skip_space(line, i);
	if (map->pt_no_t == NULL)
		map->pt_no_t = ft_join(line + i, map, 0);
	else
		return (rt(0, "the NO tpath line is duplicate", map));
	if (map->pt_no_t == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the NO texture", map));
	free_line(line);
	return (0);
}

int	parse_so_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before SO taces path ", map));
	i = skip_space(line, i);
	if (map->pt_so_t == NULL)
		map->pt_so_t = ft_join(line + i, map, 0);
	else
		return (rt(0, "the SO tpath line is duplicate", map));
	if (map->pt_so_t == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the SO texture", map));
	free_line(line);
	return (0);
}

int	parse_we_texture(char *line, t_info *map, int i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before WE taces path ", map));
	i = skip_space(line, i);
	if (map->pt_we_t == NULL)
		map->pt_we_t = ft_join(line + i, map, 0);
	else
		return (rt(0, "the WE tpath line is duplicate", map));
	if (map->pt_we_t == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the WE texture", map));
	free_line(line);
	return (0);
}

int	parse_ea_texture(char *line, t_info *map, int	i)
{
	map->pass++;
	if (line[i] != ' ')
		return (rt(0, "- Before EA taces path ", map));
	i = skip_space(line, i);
	if (map->pt_ea_t == NULL)
		map->pt_ea_t = ft_join(line + i, map, 0);
	else
		return (rt(0, "the EA tpath line is duplicate", map));
	if (map->pt_ea_t == NULL)
		return (rt(0, "-In malloc", map));
	if (found_extention(line) == 1)
		return (rt(0, "-  Wrong extension of the EA texture", map));
	free_line(line);
	return (0);
}
