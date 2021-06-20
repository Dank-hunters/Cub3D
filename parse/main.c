/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:32:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/16 18:27:32 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int main(int ac, char **av)
{
	t_info	map;

	int i = 0;
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	if (start_parse(av, &map) != 1)
	{
		dprintf(1, "thats right");
		/*while(map.map[i])
		{
			dprintf(1, "%s\n", map.map[i]);
			i++;
		}*/
	}
	return (0);
}
