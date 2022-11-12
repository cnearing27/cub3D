/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:30 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/07 19:35:51 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_err_map_exit(char *error_msg, char error_symbol)
{
	printf("Error: %s - '%c'!\n", error_msg, error_symbol);
	exit (EXIT_FAILURE);
}

void	ft_init_player_pos(t_glb *glb, char direct, int i, int j)
{
	glb->player_y = (double)j + 0.5;
	glb->player_x = (double)i + 0.5;
	if (direct == 'E')
	{
		glb->cam_pln_x = FOV;
		glb->cam_pln_y = 0;
		glb->pl_dir_x = 0;
		glb->pl_dir_y = 1;
	}
	else if (direct == 'S')
	{
		glb->cam_pln_x = 0;
		glb->cam_pln_y = -FOV;
		glb->pl_dir_x = 1;
		glb->pl_dir_y = 0;
	}
	else if (direct == 'W')
	{
		glb->cam_pln_x = -FOV;
		glb->cam_pln_y = 0;
		glb->pl_dir_x = 0;
		glb->pl_dir_y = -1;
	}
}

void	ft_check_map_symbols(char ch, int *players)
{
	if (ch != '1' && ch != '0' && ch != 'N' && ch != 'S' \
			&& ch != 'W' && ch != 'E' && ch != ' ')
		ft_err_map_exit("invalid symbol in map", ch);
	if ((ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E') && *players < 1)
		(*players)++;
	else if ((ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E') \
			&& *players == 1)
		ft_err_map_exit("more then one player position in map", ch);
}

void	ft_map_rowslen(t_glb *glb, char *row)
{
	int	len;

	len = (int)ft_strlen(row);
	if (len > glb->map.row_len)
		glb->map.row_len = len;
	if (ft_strcmp (row, "") != 0)
		glb->map.rows++;
	else
		ft_err_exit("there is an empty row in map");
}

void	ft_check_map_rows(char **rows, int i, t_glb *glb)
{
	int	i1;
	int	j;

	i1 = i;
	j = 0;
	glb->players = 0;
	while (rows[i] != 0)
	{
		j = 0;
		while (rows[i][j] != 0)
		{
			ft_check_map_symbols(rows[i][j], &glb->players);
			if (rows[i][j] == 'N' || rows[i][j] == 'S' \
				|| rows[i][j] == 'W' || rows[i][j] == 'E')
			{
				ft_init_player_pos(glb, rows[i][j], i - i1, j);
				rows[i][j] = '0';
			}
			j++;
		}
		ft_map_rowslen(glb, rows[i]);
		i++;
	}
	if (glb->players == 0)
		ft_err_exit("there is no player in map");
}
