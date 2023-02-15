/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/15 16:43:21 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static int	get_z_coord(char *line, int i, int x_max)
{
	char	**z_coords;
	int		z;

	if (!line)
		return (0);
	z_coords = ft_split(line, ' ');
	z = ft_atoi(z_coords[i]);
	i = 0;
	while (z_coords[i])
	{
		free(z_coords[i]);
		i++;
	}
	free(z_coords);
	return (z);
}

static void	fill_row(t_map *map, char *line, int y)
{
	int	i;

	i = 0;
	while (i < map->x_max)
	{
		map->matrix[y][i].x = i;
		map->matrix[y][i].y = y;
		map->matrix[y][i].z = get_z_coord(line, i, map->x_max);
		i++;
	}
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
