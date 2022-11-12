/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:40 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:41 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_size_map(char **argv)
{
	int		fd;
	int		rows;
	int		gnl_res;
	char	*str;

	rows = 0;
	str = NULL;
	gnl_res = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_err_exit("map file not found");
	while (gnl_res != 0)
	{
		gnl_res = get_next_line(fd, &str);
		free(str);
		rows++;
	}
	close(fd);
	return (rows);
}

void	ft_map_open(char **argv, char ***map)
{
	int		fd;
	int		rows;
	char	**tmp;
	int		gnl_res;
	int		i;

	gnl_res = 1;
	tmp = NULL;
	rows = ft_size_map(argv);
	tmp = (char **)malloc(sizeof(char *) * (rows + 1));
	if (tmp == NULL)
		ft_err_exit("memory allocation error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_err_exit("map file not found");
	i = 0;
	while (gnl_res != 0)
	{
		gnl_res = get_next_line(fd, &tmp[i]);
		i++;
	}
	tmp[i] = NULL;
	*map = tmp;
	close(fd);
}
