/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/18 08:22:24 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	fill_row(t_map *map, char *line, int y)
{
	char	**z_data;
	int		i;

	if (!line)
		return ;
	i = 0;
	z_data = ft_split(line, ' ');
	while (i < map->x_max)
	{
		map->matrix[y][i].x = i;
		map->matrix[y][i].y = y;
		map->matrix[y][i].z = ft_atoi(z_data[i]);
		i++;
	}
	i = 0;
	while (z_data[i])
		free(z_data[i++]);
	free(z_data);
}

t_pixel	**map_fill(char *file_name, t_map *map, int x_max, int y_max)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_hndl("Map failed to open.");
	map->matrix = malloc(sizeof(t_pixel *) * y_max);
	if (!map->matrix)
		err_hndl("Memory allocation for Map Matrix failed.");
	line = get_next_line(fd);
	while (line)
	{
		map->matrix[y] = malloc(sizeof(t_pixel) * x_max);
		fill_row(map, line, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	return (map->matrix);
}
