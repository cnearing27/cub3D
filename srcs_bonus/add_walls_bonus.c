/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_walls_add_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:41 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:42 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_choose_texture(t_wall *wall)
{
	if (wall->hit == 2)
		wall->texture_num = 4;
	else if (wall->side == 1 && wall->ray_dir_y < 0)
		wall->texture_num = 0;
	else if (wall->side == 1 && wall->ray_dir_y >= 0)
		wall->texture_num = 1;
	else if (wall->side == 0 && wall->ray_dir_x < 0)
		wall->texture_num = 2;
	else if (wall->side == 0 && wall->ray_dir_x >= 0)
		wall->texture_num = 3;
}

void	ft_choose_pixel(t_glb *glb, t_wall *wall)
{
	ft_choose_texture(wall);
	if (wall->side == 0)
		wall->wall_x = glb->player_y + wall->perp_wall_dist * wall->ray_dir_y;
	else
		wall->wall_x = glb->player_x + wall->perp_wall_dist * wall->ray_dir_x;
	wall->wall_x = wall->wall_x - floor((wall->wall_x));
	wall->texture_x = (int)(wall->wall_x * (double)TEXTURE_W);
	if (wall->side == 0 && wall->ray_dir_x > 0)
		wall->texture_x = TEXTURE_W - wall->texture_x - 1;
	if (wall->side == 1 && wall->ray_dir_y < 0)
		wall->texture_x = TEXTURE_W - wall->texture_x - 1;
	wall->step = 1.0 * TEXTURE_H / wall->line_height;
	wall->texture_pos = (wall->rend_start - WIN_H / 2 + \
						wall->line_height / 2) * wall->step;
	wall->y = wall->rend_start;
}

void	ft_pixels_screen_buf(t_glb *glb, t_wall *wall)
{
	while (wall->y < wall->rend_end)
	{
		wall->texture_y = (int)wall->texture_pos & (TEXTURE_H - 1);
		wall->texture_pos += wall->step;
		wall->color = glb->texturs[wall->texture_num] \
							[TEXTURE_H * wall->texture_y + wall->texture_x];
		if (wall->side == 1)
			wall->color = (wall->color >> 1) & 0x7F7F7F;
		glb->buf_img[wall->y][wall->x] = wall->color;
		wall->y++;
	}
}

void	ft_fill_floor_and_ceiling(t_glb *glb)
{
	int	y;
	int	x;

	y = WIN_H / 2 + 1;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			glb->buf_img[y][x] = glb->map.floor_clr;
			glb->buf_img[WIN_H - y - 1][x] = glb->map.ceiling_clr;
			x++;
		}
		y++;
	}
}
