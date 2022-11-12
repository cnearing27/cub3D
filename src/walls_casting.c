/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_walls_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:50 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:51 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda(t_glb *glb, t_wall *wall)
{
	wall->hit = 0;
	while (wall->hit == 0)
	{
		if (wall->side_dist_x < wall->side_dist_y)
		{
			wall->side_dist_x = wall->side_dist_x + wall->delta_dist_x;
			wall->map_x = wall->map_x + wall->step_x;
			wall->side = 0;
		}
		else
		{
			wall->side_dist_y = wall->side_dist_y + wall->delta_dist_y;
			wall->map_y = wall->map_y + wall->step_y;
			wall->side = 1;
		}
		if (glb->map.map_array[wall->map_x][wall->map_y] == '1')
			wall->hit = 1;
	}
}

void	ft_get_step_side_dist(t_glb *glb, t_wall *wall)
{
	if (wall->ray_dir_x < 0)
	{
		wall->step_x = -1;
		wall->side_dist_x = (glb->player_x - wall->map_x) * wall->delta_dist_x;
	}
	else
	{
		wall->step_x = 1;
		wall->side_dist_x = (wall->map_x + 1.0 - glb->player_x) * \
							wall->delta_dist_x;
	}
	if (wall->ray_dir_y < 0)
	{
		wall->step_y = -1;
		wall->side_dist_y = (glb->player_y - wall->map_y) * wall->delta_dist_y;
	}
	else
	{
		wall->step_y = 1;
		wall->side_dist_y = (wall->map_y + 1.0 - glb->player_y) * \
							wall->delta_dist_y;
	}
}

void	ft_get_position(t_glb *glb, t_wall *wall)
{
	wall->camera_x = 2 * wall->x / (double)WIN_W - 1;
	wall->ray_dir_x = glb->pl_dir_x + glb->cam_pln_x * wall->camera_x;
	wall->ray_dir_y = glb->pl_dir_y + glb->cam_pln_y * wall->camera_x;
	wall->map_x = (int)glb->player_x;
	wall->map_y = (int)glb->player_y;
	wall->delta_dist_x = fabs(1 / wall->ray_dir_x);
	wall->delta_dist_y = fabs(1 / wall->ray_dir_y);
}

void	ft_wall_size_x(t_glb *glb, t_wall *wall)
{
	if (wall->side == 0)
		wall->perp_wall_dist = (wall->map_x - glb->player_x + \
								(1 - wall->step_x) / 2) / wall->ray_dir_x;
	else
		wall->perp_wall_dist = (wall->map_y - glb->player_y + \
								(1 - wall->step_y) / 2) / wall->ray_dir_y;
	wall->line_height = (int)(WIN_H / wall->perp_wall_dist);
	wall->rend_start = -wall->line_height / 2 + WIN_H / 2;
	if (wall->rend_start < 0)
		wall->rend_start = 0;
	wall->rend_end = wall->line_height / 2 + WIN_H / 2;
	if (wall->rend_end >= WIN_H)
		wall->rend_end = WIN_H - 1;
}

void	ft_wall_casting(t_glb *glb)
{
	t_wall	wall;

	wall.x = 0;
	while (wall.x < WIN_W)
	{
		ft_get_position(glb, &wall);
		ft_get_step_side_dist(glb, &wall);
		ft_dda(glb, &wall);
		ft_wall_size_x(glb, &wall);
		ft_choose_pixel(glb, &wall);
		ft_pixels_screen_buf(glb, &wall);
		wall.x++;
	}
}
