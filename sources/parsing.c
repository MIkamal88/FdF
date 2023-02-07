/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/07 14:06:46 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_map	map_read(char *file_name)
{
	int		fd;
	t_map	map;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_hndl("Invalid map file descriptor");
	line = get_next_line(fd);
	map.x_max = count_words(line, ' ');
	return (map);
}

int	get_height(int fd)
{
	char		*line1;
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	line1 = get_next_line(fd);
	while (line1)
	{
		free(line1);
		line1 = get_next_line(fd);
		i++;
		if (line1 != 0)
		{
			free(line);
			line = ft_strdup(line1);
		}
	}
	free(line1);
	return (i);
}

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
