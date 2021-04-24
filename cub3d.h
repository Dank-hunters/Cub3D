/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:27:23 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/24 17:35:50 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_info
{
	int res_x;
	int res_y;
	int r_floor;
	int g_floor;
	int b_floor;
	int r_ceiling;
	int g_ceiling;
	int b_ceiling;

}			t_info;

int skip_space(char *str, int i);
int skip_num(char *str, int i);
int take_size(char *str, int start);
int search_keys(char *line);

int start_parse(char **av);
int parse_res(char *line, t_info *map, int i);
int parse_NO_texture(char *line, t_info *map, int i);
int parse_ceiling_color(char *line, t_info *map, int i);
int parse_floor_color(char *line, t_info *map, int i);

int parse_line_part1(char *line, int num_line, t_info *map);
int parse_line_part2(char *line, int num_line, t_info *map);
int parse_line_part3(char *line, int num_line, t_info *map);

void init_struct(t_info *map);
int	ft_strlen(char *str);
int gnl(int fd, char **line);
int main(int ac, char **av);
int take_size(char *str, int start);
#endif 
