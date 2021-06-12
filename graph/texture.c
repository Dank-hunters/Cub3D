/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:21:14 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/12 21:37:07 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
static inline int   text_get_pixel(t_info *map, int y, int x)
{
       return (y * map->res_x + x);
}
static inline int   text_get_pixel2(t_text *xpm, int y, int x)
{
       return (y * xpm->width + x);
}*/
void add_text(t_info *map, float dist, int x)
{
       int i;

       i = 0;
      // int winx;
       //int winy;
       float y;
       (void)dist;
       map->winy = (map->res_y / 2) - (map->h_wall/2);
       y = 0;
       float n_gap = (float)map->xpm[0].height / map->h_wall;
    //   dprintf(1, "gap = %f", n_gap);
       while (i <= map->h_wall)
       {
              if (map->winy + i >= 0 && map->winy + i < map->res_y && y >= 0 && y < map->xpm[0].height && map->winx >= 0 && map->winx <= map->xpm[0].width)
                     map->img.addr[(map->winy + i) * map->res_x + x] = map->xpm[0].addr[(int)y * map->xpm[0].width + map->winx];
              i++;
              y += n_gap;
       }
}