/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/18 18:49:34 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static t_win	*new_win(int w, int h)
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->height = h;
	win->width = w;
	win->m_win = mlx_new_window(win->mlx, win->width, win->height, "FdF");
	return (win);
}

static t_img	*new_img(int w, int h, t_win *window)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	if (h > window->height || w > window->width)
		err_hndl("Image frame is bigger than window");
	image->img_ptr = mlx_new_image(window->mlx, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_length), &(image->endian));
	image->w = w;
	image->h = h;
	return (image);
}

static t_fdf	*init_fdf(char *filename, int w, int h)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		err_hndl("Can't Initialize FdF.");
	fdf->map = map_read(filename);
	map_fill(filename, fdf->map, fdf->map->x_max, fdf->map->y_max);
	if (!fdf->map)
	{
		err_hndl("Can't Parse map.");
		free(fdf);
	}
	fdf->win = new_win(w, h);
	fdf->img = new_img(w, h, fdf->win);
	if (!fdf->img)
		free_map(fdf->map);
	fdf->cam = init_cam();
	if (!fdf->cam)
		free_all(fdf);
	return (fdf);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;
	char	**file_test;
	int		i;

	i = 0;
	if (argc != 2)
		err_hndl("Please enter a valid map path.");
	file_name = argv[1];
	file_test = ft_split(file_name, '.');
	while (file_test[i])
		i++;
	if (ft_strcmp(file_test[i - 1], "fdf") != 0)
		err_hndl("Please enter a valid map.");
	else
	{
		fdf = init_fdf(file_name, WINDOW_WIDTH, WINDOW_HEIGHT);
		render(fdf, TEXT_COLOR);
		mlx_hook(fdf->win->m_win, 17, 0, exit_window, fdf);
		mlx_key_hook(fdf->win->m_win, key_parse, fdf);
		mlx_loop(fdf->win->mlx);
	}
}
