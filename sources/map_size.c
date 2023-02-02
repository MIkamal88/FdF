/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/03 00:40:22 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_mapsize	map_read(char *map)
{
	int			fd;
	t_mapsize	map_coords;
	t_y_width	last_line;

	fd = open(map, O_RDONLY);
	last_line = get_height(map, fd);
	map_coords.x = get_width(last_line.line);
	map_coords.y = last_line.y;
	close(fd);
	free(last_line.line);
	return (map_coords);
}

int	get_width(char *line)
{
	char	**x_coords;
	int		*x;
	int		i;

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
