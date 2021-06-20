/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:32:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/15 17:01:44 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int ft_strlen(char *l)
{
	int i; 

	i = 0;
	while(l[i])
	{
	i++;
	}
	return(i);
}

int main(int ac, char **av)
{
	t_info	map;

	int i = 0;
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	if (parse(av, &map) != 1)
	{
		while(map.map[i])
		{
			dprintf(1, "%s\n", map.map[i]);
			i++;
		}
	}
	return (0);
}
