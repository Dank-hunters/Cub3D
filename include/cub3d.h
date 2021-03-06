/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:27:23 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/21 19:29:12 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_FORWARD 13
# define KEY_BACKWARD 1
# define KEY_GOLEFT 0
# define KEY_GORIGHT 2
# define KEY_LEAVE 53
# define RES_Y 1080
# define RES_X 1920
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../dependency/mlx/mlx.h"

typedef struct s_text
{
	void	*img;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_text;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

//stucture pour le paring
typedef struct s_info
{
	t_text	xpm[4];
	float	h_wall;
	int		winx;
	int		winy;
	int		goright;
	int		goleft;
	int		esc;
	int		pass;
	int		res_x;
	int		res_y;
	int		r_f;
	int		g_f;
	int		b_f;
	int		r_c;
	int		g_c;
	int		b_c;
	int		ccolor;
	int		fcolor;
	char	*pt_no_t;
	char	*pt_so_t;
	char	*pt_we_t;
	char	*pt_ea_t;
	char	*pt_sp_t;
	int		line_size;
	int		line_compt;
	char	*filename;
	int		start_map;
	int		tofree;
	char	view_d;
	char	**map;
	float	px;
	float	py;
	float	a_ray;
	int		proj;
	int		fov;
	float	hx;
	float	hy;
	float	angle_vision;
	float	vx;
	float	vy;
	float	h_dist;
	float	v_dist;
	float	gap;
	float	na_ray;
	int		turnright;
	int		turnleft;
	int		fward;
	int		bward;
	int		not_close;
	t_data	img;
}			t_info;

void	ft_putstr(char *str);
int		ft_ischar(char *str, char c);
int		ft_charchr(char c);
int		ft_parse_char(char *line);
char	*ft_join(char *line, t_info *map, int i);

void	errore(t_info *map);

int		ft_found_pos(t_info *map, int i, int y);
int		found_start_map(t_info *map);
int		take_info_needed(t_info *map, int fd, char *line);

int		skip_space(char *str, int i);
int		skip_num(char *str, int i);
int		take_size(char *str, int start);
int		search_keys(char *line);
void	ft_putnbr(int nb);
int		fill_flood_map(t_info *map, int y, int x);
int		start_parse(t_info *map, char **av, int ret);
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

int		init_tab_map(t_info *map);
int		initialisation_map_tab(char *line, t_info *map);
void	*free_line(char *line);
void	init_struct(t_info *map, char **av);
int		ft_strlen(char *str);
int		gnl(int fd, char **line);
int		take_size(char *str, int start);
int		rt(int param, char *str, t_info *map);
int		found_extention(char *line);
int		check_info_here(t_info *map);
void	free_map(t_info *map);
int		main(int ac, char **av);
int		init_imp(t_info *map);
void	my_mlx_pixel_put(t_info *map, int x, int y, int color);
int		graph(t_info *map);
int		key_hook(int keycode, t_info *map);

void	first_inter(t_info *map);
void	found_wall_hor(t_info *map, float ray);
void	found_wall_vert(t_info *map, float ray);
int		create_trgb(int t, int r, int g, int b);
int		exit_games(t_info *map);

int		keyrelease(int key, t_info *map);
int		keypress(int key, t_info *map);
void	event(t_info *map);
void	initss(t_info *map);
int		creat_img(t_info *map);

int		init_text(t_info *map, int i, int errror);
void	add_text(t_info *map, int x, int hoz, int i);
void	file_to_img(t_info *map);
//void	free_map(t_info *map);

int		get_next_line(int fd, char **line);
size_t	ft_strrlen(const char *str);
char	*ft_strdup(const char *s1, int leaks);
char	*ft_strjoin(char const *s1, char const *s2);
int		error(int index);
int		test_map(t_info *map);

#endif 
