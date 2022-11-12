/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:59 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:00 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_import_imgxpm(t_glb *glb, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(glb->mlx, path, &img->img_w, &img->img_h);
	if (img->img == NULL)
		ft_err_exit("xpm file error");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
										&img->len, &img->endian);
	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(glb->mlx, img->img);
}

void	ft_import_textures(t_glb *glb)
{
	t_img	img;

	ft_import_imgxpm(glb, glb->texturs[0], glb->map.north_texture, &img);
	ft_import_imgxpm(glb, glb->texturs[1], glb->map.south_texture, &img);
	ft_import_imgxpm(glb, glb->texturs[2], glb->map.east_texture, &img);
	ft_import_imgxpm(glb, glb->texturs[3], glb->map.west_texture, &img);
	ft_import_imgxpm(glb, glb->texturs[4], "textures/trapdoor.xpm", &img);
}

void	ft_init_map(t_glb *glb)
{
	glb->map.north_texture = NULL;
	glb->map.south_texture = NULL;
	glb->map.east_texture = NULL;
	glb->map.west_texture = NULL;
	glb->map.rows = 0;
	glb->map.row_len = 0;
	glb->map.count_prm = 0;
}

void	ft_init_data(t_glb *glb)
{
	glb->pl_dir_x = -1.0;
	glb->pl_dir_y = 0.0;
	glb->cam_pln_x = 0.0;
	glb->cam_pln_y = FOV;
	glb->ctrl.key_esc = 0;
	glb->ctrl.key_open = 0;
	glb->ctrl.key_up = 0;
	glb->ctrl.key_down = 0;
	glb->ctrl.key_left = 0;
	glb->ctrl.key_right = 0;
	glb->ctrl.key_mouse = 1;
	glb->speed_rotate = 0.04;
	glb->speed_move = 0.04;
	glb->mlx = mlx_init();
	if (glb->mlx == NULL)
		ft_err_exit("mlx error");
	glb->win = mlx_new_window(glb->mlx, WIN_W, WIN_H, WIN_NAME);
	glb->img.img = mlx_new_image(glb->mlx, WIN_W, WIN_H);
	if (glb->win == NULL || glb->img.img == NULL)
		ft_err_exit("mlx error");
	glb->img.data = (int *)mlx_get_data_addr(glb->img.img, &glb->img.bpp, \
					&glb->img.len, &glb->img.endian);
	ft_init_map(glb);
}
