/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:25 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:26 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_glb *glb)
{
	if (glb->mlx != 0)
	{
		mlx_clear_window(glb->mlx, glb->win);
		mlx_destroy_window(glb->mlx, glb->win);
	}
	exit (EXIT_SUCCESS);
}

void	ft_render(t_glb *glb)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			glb->img.data[y * WIN_W + x] = glb->buf_img[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(glb->mlx, glb->win, glb->img.img, 0, 0);
}

int	ft_game_loop(t_glb *glb)
{
	ft_fill_floor_and_ceiling(glb);
	ft_wall_casting(glb);
	ft_render(glb);
	ft_key_action(glb);
	return (0);
}

int	ft_textures_malloc(t_glb *glb)
{
	int	i;

	glb->texturs = (int **)malloc(sizeof(int *) * 5);
	if (glb->texturs == NULL)
		ft_err_exit("memory allocation error");
	i = 0;
	while (i < 5)
	{
		glb->texturs[i] = (int *)malloc(sizeof(int) * (TEXTURE_H * TEXTURE_W));
		if (glb->texturs[i] == NULL)
			ft_err_exit("memory allocation error");
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = malloc(sizeof(t_glb));
	if (glb == NULL)
		ft_err_exit("memory allocation error");
	ft_init_data(glb);
	ft_map_checks(argc, argv);
	ft_parser_mapfile(argv, glb);
	ft_textures_malloc(glb);
	ft_import_textures(glb);
	mlx_loop_hook(glb->mlx, &ft_game_loop, glb);
	mlx_hook(glb->win, PRESS, 0, &ft_key_press, glb);
	mlx_hook(glb->win, RELEASE, 0, &ft_key_release, glb);
	mlx_hook(glb->win, REDCROSS, 0, ft_close_window, glb);
	mlx_loop(glb->mlx);
}
