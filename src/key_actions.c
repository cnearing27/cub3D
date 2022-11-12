/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:20 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:21 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_glb *glb)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		glb->ctrl.key_up = 1;
	else if (key == LEFT)
		glb->ctrl.key_left = 1;
	else if (key == DOWN)
		glb->ctrl.key_down = 1;
	else if (key == RIGHT)
		glb->ctrl.key_right = 1;
	else if (key == ARROW_RIGHT)
		glb->ctrl.key_arr_right = 1;
	else if (key == ARROW_LEFT)
		glb->ctrl.key_arr_left = 1;
	return (0);
}

int	ft_key_release(int key, t_glb *glb)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		glb->ctrl.key_up = 0;
	else if (key == LEFT)
		glb->ctrl.key_left = 0;
	else if (key == DOWN)
		glb->ctrl.key_down = 0;
	else if (key == RIGHT)
		glb->ctrl.key_right = 0;
	else if (key == ARROW_RIGHT)
		glb->ctrl.key_arr_right = 0;
	else if (key == ARROW_LEFT)
		glb->ctrl.key_arr_left = 0;
	return (0);
}

void	ft_player_rotate_r(t_glb *glb)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = glb->pl_dir_x;
	old_plane_x = glb->cam_pln_x;
	glb->pl_dir_x = glb->pl_dir_x * cos(-glb->speed_rotate) - \
					glb->pl_dir_y * sin(-glb->speed_rotate);
	glb->pl_dir_y = old_dir_x * sin(-glb->speed_rotate) + \
					glb->pl_dir_y * cos(-glb->speed_rotate);
	glb->cam_pln_x = glb->cam_pln_x * cos(-glb->speed_rotate) - \
					glb->cam_pln_y * sin(-glb->speed_rotate);
	glb->cam_pln_y = old_plane_x * sin(-glb->speed_rotate) + \
					glb->cam_pln_y * cos(-glb->speed_rotate);
}

void	ft_player_rotate_l(t_glb *glb)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = glb->pl_dir_x;
	old_plane_x = glb->cam_pln_x;
	glb->pl_dir_x = glb->pl_dir_x * cos(glb->speed_rotate) - \
					glb->pl_dir_y * sin(glb->speed_rotate);
	glb->pl_dir_y = old_dir_x * sin(glb->speed_rotate) + \
					glb->pl_dir_y * cos(glb->speed_rotate);
	glb->cam_pln_x = glb->cam_pln_x * cos(glb->speed_rotate) - \
					glb->cam_pln_y * sin(glb->speed_rotate);
	glb->cam_pln_y = old_plane_x * sin(glb->speed_rotate) + \
					glb->cam_pln_y * cos(glb->speed_rotate);
}

void	ft_key_action(t_glb *glb)
{
	if (glb->ctrl.key_up)
		ft_player_forward(glb);
	if (glb->ctrl.key_down)
		ft_player_backward(glb);
	if (glb->ctrl.key_left)
		ft_player_left(glb);
	if (glb->ctrl.key_right)
		ft_player_right(glb);
	if (glb->ctrl.key_arr_right)
		ft_player_rotate_r(glb);
	if (glb->ctrl.key_arr_left)
		ft_player_rotate_l(glb);
	if (glb->ctrl.key_esc)
		exit(0);
}
