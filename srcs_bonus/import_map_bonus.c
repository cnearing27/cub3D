/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_import_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:23 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:24 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_map_to_array(char **rows, int i, t_glb *glb)
{
	int	n;
	int	j;

	glb->map.map_array = malloc(sizeof(char *) * glb->map.rows);
	if (glb->map.map_array == NULL)
		ft_err_exit("memory allocation error");
	j = 0;
	while (j < glb->map.rows)
	{
		glb->map.map_array[j] = malloc(sizeof(char) * glb->map.row_len);
		if (glb->map.map_array[j] == NULL)
			ft_err_exit("memory allocation error");
		ft_memset(glb->map.map_array[j], ' ', glb->map.row_len);
		j++;
	}
	j = 0;
	while (j < glb->map.rows)
	{
		n = -1;
		while (rows[i][++n])
			glb->map.map_array[j][n] = rows[i][n];
		j++;
		i++;
	}
}

void	ft_texture_save(char **split_row, char **path, t_glb *glb)
{
	if (split_row[2] != NULL)
		ft_err_exit("bad parameters");
	ft_texture_file_check(split_row[1]);
	if (*path == NULL)
	{
		*path = split_row[1];
		free(split_row[0]);
		glb->map.count_prm++;
	}
	else
		ft_err_exit("the texture is doublicated");
}

void	ft_color_save(char **split_row, char **color, t_glb *glb)
{
	char	**split_color;

	if (split_row[2] != 0)
		ft_err_exit("bad parameters!");
	if (*color != NULL)
		ft_err_exit("color parameter is doublicated!!!");
	*color = split_row[1];
	glb->map.count_prm++;
	split_color = ft_split(*color, ',');
	if (ft_strncmp(split_row[0], "C", 1) == 0)
	{
		glb->map.ceiling_clr = ft_color_check(split_color);
		free(split_row[0]);
	}
	if (ft_strncmp(split_row[0], "F", 1) == 0)
	{
		glb->map.floor_clr = ft_color_check(split_color);
		free(split_row[0]);
	}
	ft_free_mem_array(split_color);
}
