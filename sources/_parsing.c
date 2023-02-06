/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/06 09:09:59 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

// t_pixel	x_elements(char *line)
// {
// 	t_pixel	pixel;
// 	char	**x_total;
// 	int		*n;
// 	int		i;

// 	i = 0;
// 	x_total = ft_split(line, ' ');
// 	while (x_total[i])
// 	{
// 		n[i] = ft_atoi(x_total[i]);
// 		if (n[i] != 0)
// 		{
// 			pixel.x = i * 10;
// 			pixel.z = n[i];
// 		}
// 		else
// 		{
// 			pixel.x = i * 10;
// 			pixel.z = 0;
// 		}
// 		i++;
// 	}
// 	free(line);
// 	return (pixel);
// }

// t_pixel	y_elements(char *map, int fd)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// 	return (i);
// }

// t_mapsize	map_read(char *map_path)
// {
// 	int		fd;
// 	char	*line;
// 	t_pixel	pixel;
// 	int		x_max;
// 	int		y_max;

// 	fd = open(map_path, O_RDONLY);
// 	if (!line)
// 		line = get_next_line(fd);
// 	x_max =
// 	while (line)
// 	{

// 	}
// 	close(fd);
// }
