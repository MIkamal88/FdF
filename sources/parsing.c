/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/31 16:25:14 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

char	*map_read_line(char *map)
{
	int		fd;
	char	*line1;

	fd = open(map, O_RDONLY);
	line1 = get_next_line(fd);
	close(fd);
	return (line1);
}

int	x_elements(char *line)
{
	char	**x_coords;
	int		*x;
	int		i;

	i = 0;
	x_coords = ft_split(line, ' ');
	while (x_coords[i])
	{
		x[i] = ft_atoi(x_coords[i]);
		i++;
	}
	free(line);
	return (i);
}

int	y_elements(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}
