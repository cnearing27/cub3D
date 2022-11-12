/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_minimap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:32 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:33 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_put_obj_minimap(t_glb *glb, int x, int y, int color)
{
	int	x_old;
	int	x1;
	int	y1;

	y1 = 0;
	x_old = x;
	while (y1 < MINIMAP)
	{
		x = x_old;
		x1 = 0;
		while (x1 < MINIMAP)
		{
			glb->img.data[y * WIN_W + x] = color;
			x1++;
			x++;
		}
		y1++;
		y++;
	}
}

void	ft_render_minimap(t_glb *glb, t_minimap *mimap)
{
	if (glb->map.map_array[mimap->y][mimap->x] == '0')
		ft_put_obj_minimap(glb, mimap->x2, mimap->y2, LIGHTGREY);
	if (glb->map.map_array[mimap->y][mimap->x] == '1')
		ft_put_obj_minimap(glb, mimap->x2, mimap->y2, BLUE);
	if (glb->map.map_array[mimap->y][mimap->x] == '2'
		|| glb->map.map_array[mimap->y][mimap->x] == '3')
		ft_put_obj_minimap(glb, mimap->x2, mimap->y2, LIGHTBLUE);
	ft_put_obj_minimap(glb, (int) glb->player_y * MINIMAP, \
		(int) glb->player_x * MINIMAP, RED);
}

void	ft_minimap(t_glb *glb)
{
	t_minimap	mimap;

	mimap.y = 0;
	mimap.y2 = 0;
	while (mimap.y < glb->map.rows)
	{
		mimap.x = 0;
		mimap.x2 = 0;
		while (mimap.x < glb->map.row_len)
		{
			ft_render_minimap(glb, &mimap);
			mimap.x2 = mimap.x2 + MINIMAP;
			mimap.x++;
		}
		mimap.y2 = mimap.y2 + MINIMAP;
		mimap.y++;
	}
}
