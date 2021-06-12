/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:18:31 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/07 17:42:18 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	n;

	n = nb % 10 + 48;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &n, 1);
}

int	free_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (1);
}

int	rt(int param, char *str, t_info *map)
{
	if (param <= 0)
		write(1, "Error\n", 6);
	if (param == -1)
		ft_putstr("- Data error in ceiling colorimetry\n");
	if (param == -2)
		ft_putstr("- Data error in resolution\n");
	if (param == -3)
		ft_putstr("- Data error in floor colorimetry\n");
	ft_putstr(str);
	if (param >= 0)
		ft_putnbr(param);
	(void)map;
	return (1);
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

int	check_info_here(t_info *map)
{
	if (map->res_x == -1 || map->res_y == -1 || map->r_floor == -1 \
			|| map->g_floor == -1 || map->b_floor == -1 \
			|| map->r_ceiling == -1 || map->g_ceiling == -1 \
			|| map->b_ceiling == -1)
		return (1);
	if (map->path_to_no_texture == NULL \
			|| map->path_to_so_texture == NULL \
			|| map->path_to_we_texture == NULL \
			|| map->path_to_ea_texture == NULL \
			|| map->path_to_sprite_texture == NULL)
		return (1);
	return (0);
}
