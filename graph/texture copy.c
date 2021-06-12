/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:21:14 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/11 14:34:03 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void add_text(t_info *map)
{
   // dprintf(1, "ta mere1");
    map->xpm[0].img = mlx_xpm_file_to_image(map->img.mlx, map->path_to_no_texture, &map->xpm[0].width, &map->xpm[0].height);
    if (map->xpm[0].img != NULL)
        map->xpm[0].addr = (int *)mlx_get_data_addr(map->xpm[0].img, &map->xpm[0].bits_per_pixel, &map->xpm[0].line_length,
								&map->xpm[0].endian);  
    else
           dprintf(1, "ta mere2");
    if  (map->xpm[0].addr == NULL)
    {
           dprintf(1, "ta mere ");
           exit(0);
    }

int     winx;
int     winy;
int     x;
int     y;

winx = 10;
winy = 10;
y = 0;

while (y < map->xpm[0].height)
{
    x = map->res_x/2 - map->h_wall/2;;
    winx = 0;
    while (x < map->xpm[0].width)
    {
        
        if (winx < (map->res_x/2 + map->h_wall/2) && winy < map->res_y)
            map->img.addr[winy * map->res_x + winx] = map->xpm[0].addr[y * map->xpm[0].width+ x];
        x++;
        winx++;
    }
    winy++;
    y++;
}
}

// ca commence a : rex_x/2 - h_wall/2
// fini sur res_x/2 + h_wall/2