/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:35 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:36 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mouse_rotate_right(t_glb *glb, int diff, int x, int y)
{
	glb->ctrl.mouse_rotate = x;
	while (diff-- != 0)
		ft_player_rotate_r(glb);
	if (x > (int)(WIN_W * 0.7))
	{
		mlx_mouse_move(glb->win, (int)(WIN_W / 2), y);
		glb->ctrl.mouse_rotate = (int)(WIN_W / 2);
	}
}

void	ft_mouse_rotate_left(t_glb *glb, int diff, int x, int y)
{
	glb->ctrl.mouse_rotate = x;
	while (diff-- != 0)
		ft_player_rotate_l(glb);
	if (x < (int)(WIN_W * 0.3))
	{
		mlx_mouse_move(glb->win, (int)(WIN_W / 2), y);
		glb->ctrl.mouse_rotate = (int)(WIN_W / 2);
	}
}

int	ft_mouse_rotate(int x, int y, t_glb *glb)
{
	int	diff;

	if (glb->ctrl.key_mouse == 1)
	{
		mlx_mouse_hide();
		diff = abs(glb->ctrl.mouse_rotate - x) / 2;
		if (diff > 3)
			diff = 3;
		if (y < (int)(WIN_H * 0.3) || y > (int)(WIN_H * 0.7))
			mlx_mouse_move(glb->win, x, (int)(WIN_H / 2));
		if (x > glb->ctrl.mouse_rotate)
			ft_mouse_rotate_right(glb, diff, x, y);
		else if (x < glb->ctrl.mouse_rotate)
			ft_mouse_rotate_left(glb, diff, x, y);
	}
	else
		mlx_mouse_show();
	return (0);
}
