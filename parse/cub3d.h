/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:27:23 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/27 18:08:14 by cguiot           ###   ########lyon.fr   */
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
	int 	pass;
	int 	res_x;
	int 	res_y;
	int 	r_floor;
	int 	g_floor;
	int 	b_floor;
	int 	r_ceiling;
	int 	g_ceiling;
	int 	b_ceiling;
	char	*path_to_no_texture;
	char	*path_to_so_texture;
	char	*path_to_we_texture;
	char	*path_to_ea_texture;
	char	*path_to_sprite_texture;
	int		line_size;

}			t_info;

int skip_space(char *str, int i);
int skip_num(char *str, int i);
int take_size(char *str, int start);
int search_keys(char *line, t_info *map);

int initialisation_map_tab(char *line, int line_compt, t_info *map);
int start_parse(char **av);
int parse_res(char *line, t_info *map, int i);
int parse_ceiling_color(char *line, t_info *map, int i);
int parse_floor_color(char *line, t_info *map, int i);
int parse_no_texture(char *line, t_info *map, int i);
int parse_so_texture(char *line, t_info *map, int i);
int parse_we_texture(char *line, t_info *map, int i);
int parse_ea_texture(char *line, t_info *map, int i);
int parse_sprite_texture(char *line, t_info *map, int i);
int parse_map(char *filename, t_info *map, int fd, int num_line);

int parse_line_part1(char *line, int num_line, t_info *map);
int parse_line_part2(char *line, int num_line, t_info *map);
int parse_line_part3(char *line, int num_line, t_info *map);

void ft_free_path(t_info *map);
int free_line(char *line);
void init_struct(t_info *map);
int	ft_strlen(char *str);
int gnl(int fd, char **line);
int main(int ac, char **av);
int take_size(char *str, int start);
int rt(int param, char *str, t_info *map);
char *scopy(char *str, int start);
int found_extention(char *line);
int check_info_here(t_info *map);
#endif 
