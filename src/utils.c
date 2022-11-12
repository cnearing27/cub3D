/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:45 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:46 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_is_num(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_rgb_to_int(int r, int g, int b)
{
	int	color;

	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}

int	ft_color_check(char **color)
{
	int	rgb[3];
	int	i;
	int	color_int;

	i = 0;
	while (i < 3)
	{
		if (ft_str_is_num(color[i]) != 0 && ft_atoi(color[i]) <= 255)
			rgb[i] = ft_atoi(color[i]);
		else
			ft_err_exit("color number is incorrect");
		i++;
	}
	color_int = ft_rgb_to_int(rgb[0], rgb[1], rgb[2]);
	return (color_int);
}

void	ft_free_mem_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
