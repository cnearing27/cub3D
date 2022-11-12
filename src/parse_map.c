/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:43 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:44 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_find_param_name(char *str)
{
	if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0
		|| ft_strcmp(str, "WE") == 0 || ft_strcmp(str, "EA") == 0
		|| ft_strcmp(str, "C") == 0 || ft_strcmp(str, "F") == 0)
		return (1);
	return (0);
}

void	ft_params_save(t_glb *glb, char **split_row)
{
	if (ft_strcmp(split_row[0], "NO") == 0)
		ft_texture_save(split_row, &glb->map.north_texture, glb);
	else if (ft_strcmp(split_row[0], "SO") == 0)
		ft_texture_save(split_row, &glb->map.south_texture, glb);
	else if (ft_strcmp(split_row[0], "WE") == 0)
		ft_texture_save(split_row, &glb->map.west_texture, glb);
	else if (ft_strcmp(split_row[0], "EA") == 0)
		ft_texture_save(split_row, &glb->map.east_texture, glb);
	else if (ft_strcmp(split_row[0], "C") == 0)
		ft_color_save(split_row, &glb->map.ceiling, glb);
	else if (ft_strcmp(split_row[0], "F") == 0)
		ft_color_save(split_row, &glb->map.floor, glb);
}

int	ft_emptyline(char **rows, int *i, char **split_row)
{
	if (split_row[0] == NULL)
	{
		ft_free_mem_array(split_row);
		(*i)++;
		return (1);
	}
	if (rows[*i][0] == '\n')
	{
		ft_free_mem_array(split_row);
		(*i)++;
		return (1);
	}
	return (0);
}

int	ft_pars_params(char ***map, t_glb *glb, int i)
{
	char	**rows;
	char	**split_row;

	split_row = NULL;
	rows = *map;
	while (rows[i] != NULL)
	{
		split_row = ft_split(rows[i], ' ');
		if (ft_emptyline(rows, &i, split_row))
			continue ;
		if (ft_find_param_name(split_row[0]))
			ft_params_save(glb, split_row);
		else if (ft_emptyline(rows, &i, split_row))
			continue ;
		else
		{
			if (glb->map.count_prm != 6)
				ft_err_exit("map doesn't contain all parameters");
			break ;
		}
		i++;
		free(split_row);
	}
	ft_free_mem_array(split_row);
	return (i);
}

void	ft_parser_mapfile(char **argv, t_glb *glb)
{
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	ft_map_open(argv, &map);
	i = ft_pars_params(&map, glb, 0);
	ft_check_map_rows(map, i, glb);
	ft_map_to_array(map, i, glb);
	ft_check_map_border_row(glb->map.map_array, glb);
	ft_check_map_border_column(glb->map.map_array, glb);
	ft_check_contour_map_in_rows(glb->map.map_array, glb);
	ft_check_contour_map_in_columns(glb->map.map_array, glb);
	ft_free_mem_array(map);
}
