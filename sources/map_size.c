/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/05 19:23:35 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_map	map_read(char *file_name)
{
	int			fd;
	t_map		map;
	t_y_width	last_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_hndl("Invalid map file descriptor");
	last_line = get_height(file_name, fd);
	map.x_max = get_width(last_line.line);
	map.y_max = last_line.y;
	close(fd);
	free(last_line.line);
	return (map);
}

int	get_width(char *line)
{
	char	**x_coords;
	int		*x;
	int		i;

	if (!line)
		return (0);
	i = 0;
	x = malloc(sizeof(int));
	x_coords = ft_split(line, ' ');
	while (x_coords[i])
	{
		x[i] = ft_atoi(x_coords[i]);
		i++;
	}
	return (i);
}

t_y_width	get_height(char *map, int fd)
{
	char		*line1;
	char		*line;
	int			i;
	t_y_width	y_total;

	i = 0;
	line1 = get_next_line(fd);
	while (line1)
	{
		line1 = get_next_line(fd);
		i++;
		if (line1 != 0)
			line = ft_strdup(line1);
	}
	y_total.line = line;
	y_total.y = i;
	return (y_total);
}

t_pixel	**init_coords(int height, int width)
{
	t_pixel	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_pixel *));
	i = 0;
	if (!coordinates)
		return (NULL);
	while (i < width)
	{
		coordinates[i] = malloc(height * sizeof(t_pixel));
		if (!coordinates)
			return (NULL);
		j = 0;
		while (j < height)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}
