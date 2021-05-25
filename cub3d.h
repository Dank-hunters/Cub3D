/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:27:23 by cguiot            #+#    #+#             */
/*   Updated: 2021/05/25 20:58:45 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 13
# define KEY_DOWN 1

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_idd 
{
int gap; // angle d un pixel par raport au joueur
int proj;  // distance entre le joueur et l ecran
}				t_idd;

typedef struct s_coord
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int step;

}			t_coord;

typedef struct	s_data
{

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;


//stucture pour le paring
typedef struct s_info
{
	int		pass;
	int		res_x;
	int		res_y;
	int		r_floor;
	int		g_floor;
	int		b_floor;
	int		r_ceiling;
	int		g_ceiling;
	int		b_ceiling;
	char	*path_to_no_texture;
	char	*path_to_so_texture;
	char	*path_to_we_texture;
	char	*path_to_ea_texture;
	char	*path_to_sprite_texture;
	int		line_size;
	int 	line_compt;
	char	*filename;
	int		start_map;
	int		tofree;
	char	view_d;
	char	**map;
	float	pos_x;
	float	pos_y;
	float 	angle_ray;
	int		proj;
	int 	fov;
	float	horz_x;
	float	horz_y;
	float	angle_vision;
	float	vert_x;
	float	vert_y;
	float	h_dist;
	float	v_dist;
	float	gap;

	int		turnright;
	int		turnleft;
	t_data	img;
}			t_info;


int		ft_ischar(char *str, char c);
int		ft_charchr(char c);
int		ft_parse_char(char *line);
char	*ft_join(char *line, t_info *map);

int		found_start_map(t_info *map);
int		take_info_needed(t_info *map, int fd, char *line);

int		skip_space(char *str, int i);
int		skip_num(char *str, int i);
int		take_size(char *str, int start);
int		search_keys(char *line, t_info *map);

int		start_parse(char **av, t_info *map);
int		parse_res(char *line, t_info *map, int i);
int		parse_ceiling_color(char *line, t_info *map, int i);
int		parse_floor_color(char *line, t_info *map, int i);
int		parse_no_texture(char *line, t_info *map, int i);
int		parse_so_texture(char *line, t_info *map, int i);
int		parse_we_texture(char *line, t_info *map, int i);
int		parse_ea_texture(char *line, t_info *map, int i);
int		parse_sprite_texture(char *line, t_info *map, int i);
int		parse_map(t_info *map);
int		parse_line_part1(char *line, t_info *map);
int		parse_line_part2(char *line, t_info *map);
int		parse_line_part3(char *line, t_info *map);

int		initialisation_map_tab(char *line, t_info *map);
int		free_line(char *line);
void	init_struct(t_info *map);
int		ft_strlen(char *str);
int		gnl(int fd, char **line);
int		take_size(char *str, int start);
int		rt(int param, char *str, t_info *map);
int		found_extention(char *line);
int		check_info_here(t_info *map);

int		main(int ac, char **av);

void    my_mlx_pixel_put(t_info *map, int x, int y, int color);
int    graph(t_info *map);
int	key_hook(int keycode, t_info *map);



void first_horz(t_info *map, float angle_ray);
void first_vert(t_info *map, ft angle_ray);
void found_wall_hor(t_info *map, float angle_ray);
void found_wall_vert(t_info *map, float angle_ray);


void initss(t_info *map);
int	creat_img(t_info *map);
#endif 


