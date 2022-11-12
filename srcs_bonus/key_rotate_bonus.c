/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:08 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:09 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
