/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:53 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/07 19:28:16 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../miniLibx/mlx.h"

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define REDCROSS 17
# define PRESS 2
# define RELEASE 3

# define WIN_W 1500
# define WIN_H 1000
# define TEXTURE_W 16
# define TEXTURE_H 16
# define FOV 0.66
# define WIN_NAME "cub3"

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		row_len;
	int		rows;
	int		count_prm;
	char	*ceiling;
	char	*floor;
	int		ceiling_clr;
	int		floor_clr;
	char	**map_array;
}			t_map;

typedef struct s_wall
{
	int		x;
	int		y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		rend_start;
	int		rend_end;
	double	wall_x;
	int		texture_num;
	int		texture_x;
	int		texture_y;
	double	texture_pos;
	double	step;
	int		color;
}			t_wall;

typedef struct s_img
{
	void	*img;
	int		len;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
	int		*data;
}			t_img;

typedef struct s_controls
{
	int		key_open;
	int		key_esc;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		key_arr_left;
	int		key_arr_right;
}			t_controls;

typedef struct s_glb
{
	t_img		img;
	t_map		map;
	t_controls	ctrl;
	double		player_x;
	double		player_y;
	double		pl_dir_x;
	double		pl_dir_y;
	double		cam_pln_x;
	double		cam_pln_y;
	double		speed_rotate;
	double		speed_move;
	int			players;
	void		*win;
	void		*mlx;
	int			**texturs;
	int			buf_img[WIN_H][WIN_W];
}				t_glb;

int		ft_strcmp(char *str1, char *str2);
void	ft_init_data(t_glb *glb);
void	ft_import_textures(t_glb *glb);
int		ft_key_press(int key, t_glb *glb);
int		ft_key_release(int key, t_glb *glb);
void	ft_key_action(t_glb *glb);
void	ft_wall_casting(t_glb *glb);
void	ft_fill_floor_and_ceiling(t_glb *glb);
void	ft_render(t_glb *glb);
void	ft_choose_pixel(t_glb *glb, t_wall *wall);
void	ft_pixels_screen_buf(t_glb *glb, t_wall *wall);
void	ft_player_rotate_l(t_glb *glb);
void	ft_player_rotate_r(t_glb *glb);
void	ft_player_forward(t_glb *glb);
void	ft_player_left(t_glb *glb);
void	ft_player_right(t_glb *glb);
void	ft_player_backward(t_glb *glb);
void	ft_map_checks(int argc, char **argv);
void	ft_pars_map(char **argv, t_glb *data);
void	ft_parser_mapfile(char **argv, t_glb *glb);
void	ft_err_exit(char *err_msg);
void	ft_init_map(t_glb *glb);
int		ft_str_is_num(const char *str);
int		ft_rgb_to_int(int r, int g, int b);
int		ft_color_check(char **color);
void	ft_param_validation(t_glb *data);
void	ft_check_map_border_row(char **map, t_glb *glb);
void	ft_check_map_border_column(char **map, t_glb *glb);
void	ft_check_contour_map_in_rows(char **map, t_glb *glb);
void	ft_check_contour_map_in_columns(char **map, t_glb *glb);
void	ft_map_open(char **argv, char ***map);
void	ft_check_map_rows(char **rows, int i, t_glb *glb);
void	ft_map_to_array(char **rows, int i, t_glb *glb);
void	ft_params_save(t_glb *glb, char **split_row);
void	ft_texture_save(char **split_row, char **path, t_glb *glb);
void	ft_color_save(char **split_row, char **color, t_glb *glb);
void	ft_err_map_exit(char *error_msg, char error_symbol);
void	ft_map_err_symb_exit(char error, char symbol, int i, int j);
void	ft_free_mem_array(char **array);
void	ft_texture_file_check(char *file_path);

#endif
