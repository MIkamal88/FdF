/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/08 10:41:09 by mshehata         ###   ########.fr       */
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
	free(line);
	map.y_max = get_height(fd);
	close(fd);
	return (map);
}

int	get_height(int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (i);
}
