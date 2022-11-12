/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_handler_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:05 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:06 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_player_forward_bonus(t_glb *glb)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(glb->player_x + glb->pl_dir_x * glb->speed_move);
	nxt_y = (int)(glb->player_y);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
		glb->player_x = glb->player_x + glb->pl_dir_x * glb->speed_move;
	nxt_x = (int)(glb->player_x);
	nxt_y = (int)(glb->player_y + glb->pl_dir_y * glb->speed_move);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
		glb->player_y = glb->player_y + glb->pl_dir_y * glb->speed_move;
}

void	ft_player_backward_bonus(t_glb *glb)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(glb->player_x - glb->pl_dir_x * glb->speed_move);
	nxt_y = (int)(glb->player_y);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
		glb->player_x = glb->player_x - glb->pl_dir_x * glb->speed_move;
	nxt_x = (int)(glb->player_x);
	nxt_y = (int)(glb->player_y - glb->pl_dir_y * glb->speed_move);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
		glb->player_y = glb->player_y - glb->pl_dir_y * glb->speed_move;
}

void	ft_player_left_bonus(t_glb *glb)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(glb->player_x - glb->cam_pln_x * glb->speed_move);
	nxt_y = (int)(glb->player_y - glb->cam_pln_y * glb->speed_move);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
	{
		glb->player_x = glb->player_x - glb->cam_pln_x * glb->speed_move;
		glb->player_y = glb->player_y - glb->cam_pln_y * glb->speed_move;
	}
}

void	ft_player_right_bonus(t_glb *glb)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(glb->player_x + glb->cam_pln_x * glb->speed_move);
	nxt_y = (int)(glb->player_y + glb->cam_pln_y * glb->speed_move);
	if (glb->map.map_array[nxt_x][nxt_y] == '0' \
				|| glb->map.map_array[nxt_x][nxt_y] == '3')
	{
		glb->player_x = glb->player_x + glb->cam_pln_x * glb->speed_move;
		glb->player_y = glb->player_y + glb->cam_pln_y * glb->speed_move;
	}
}
