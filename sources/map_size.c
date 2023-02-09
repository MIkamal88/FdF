/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:40:41 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/09 14:32:58 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static int	get_height(int fd)
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

static int	count_x(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->matrix = NULL;
	map->x_max = 0;
	map->y_max = 0;
	return (map);
}

t_map	*map_read(char *file_name)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = init_map();
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_hndl("Can't read Map size.");
	line = get_next_line(fd);
	map->x_max = count_x(line, ' ');
	free(line);
	map->y_max = get_height(fd);
	close(fd);
	return (map);
}
