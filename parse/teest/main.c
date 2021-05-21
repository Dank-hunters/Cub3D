/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:32:03 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/15 11:10:33 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	t_map	cub;
	int i = 0;
	(void)av;
	if (ac == 1)
		return (rt(0, "-Missing map config", &map));
	if (parse(av, &map, &cub) != 1)
	{
		dprintf(1, "\nle path : %s\n", map.path_to_no_texture);
		dprintf(1, "\n");
		while(cub.map[i])
		{
			dprintf(1, "%s\n", cub.map[i]);
			i++;
		}
	}
	return (0);
}
