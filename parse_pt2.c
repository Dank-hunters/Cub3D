/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:02:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/24 17:04:30 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_res(char *line, t_info *map, int i)
{
	if (line[i] != ' ')
		return(1); //"mauvais format de resolution (apres le R)"
	i = skip_space(line, i);
	if (line[i] <= '0' && line[i] >= '9')
		return (1); //"mauvais format dans les decimaux"
	map->res_x = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ' ')
		return(1); //("mauvais format de resolution (entre le x et y)"
	i = skip_space(line, i);
	if (line[i] <= '0' && line[i] >= '9')
		return (1);  //mauvaise resolutiom dans les decimaux
	map->res_y = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return(1); //caractere en trop dans le resolution;
	return (0); //le parse de la resolution est ok
}

int parse_NO_texture(char *line, t_info *map, int i)
{
	if (line[i] != ' ')
		return (1);  // erreur avant le path de la texture nord
	i = skip_space(line, i);
	if (line[i] != '.')
		return (1); //erreur avant le path
	return (0);
}

int parse_ceiling_color(char *line, t_info *map, int i)
{
	if (line[i] != ' ')
		return(1); //erreur avant la premiere info de texture du floor
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (1); //"mauvais format dans les decimaux"
	map->r_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1); //erreur apres le r
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1); //erreur entre r et g
	map->g_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1); //erreur apres le g
	i  = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1); //erreur entre g et b
	map->b_ceiling = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return(1); //caractere en trop dans le resolution;
	return (0);
}

int parse_floor_color(char *line, t_info *map, int i)
{
	if (line[i] != ' ')
		return(1); //erreur avant la premiere info de texture du floor
	i = skip_space(line, i);
	if (line[i] < '0' && line[i] > '9')
		return (1); //"mauvais format dans les decimaux"
	map->r_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1); //erreur apres le r
	i = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1); //erreur entre r et g
	map->g_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i] != ',')
		return (1); //erreur apres le g
	i  = skip_space(line, i + 1);
	if (line[i] > '9' || line[i] < '0')
		return (1); //erreur entre g et b
	map->b_floor = take_size(line, i);
	i = skip_num(line, i);
	if (line[i])
		return(1); //caractere en trop dans le resolution;
	return (0);
}
