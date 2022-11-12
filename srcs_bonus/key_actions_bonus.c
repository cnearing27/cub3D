/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_actions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:02 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:03 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	else if (key == OPEN)
		glb->ctrl.key_open = 1;
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
	else if (key == ARROW_UP)
		glb->ctrl.key_arr_up = 1;
	else if (key == ARROW_DOWN)
		glb->ctrl.key_arr_down = 1;
	else if (key == MOUSE_SHOW)
		glb->ctrl.key_mouse = !glb->ctrl.key_mouse;
	return (0);
}

void	ft_fov_plus(t_glb *glb)
{
	glb->cam_pln_x *= 1.1;
	glb->cam_pln_y *= 1.1;
	glb->ctrl.key_arr_up = 0;
}

void	ft_fov_minus(t_glb *glb)
{
	glb->cam_pln_x *= 0.9;
	glb->cam_pln_y *= 0.9;
	glb->ctrl.key_arr_down = 0;
}

void	ft_key_action(t_glb *glb)
{
	if (glb->ctrl.key_up)
		ft_player_forward_bonus(glb);
	if (glb->ctrl.key_down)
		ft_player_backward_bonus(glb);
	if (glb->ctrl.key_left)
		ft_player_left_bonus(glb);
	if (glb->ctrl.key_right)
		ft_player_right_bonus(glb);
	if (glb->ctrl.key_arr_up)
		ft_fov_plus(glb);
	if (glb->ctrl.key_arr_down)
		ft_fov_minus(glb);
	if (glb->ctrl.key_arr_right)
		ft_player_rotate_r(glb);
	if (glb->ctrl.key_arr_left)
		ft_player_rotate_l(glb);
	if (glb->ctrl.key_esc)
		exit(0);
}
