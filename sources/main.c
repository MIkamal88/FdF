/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/10 11:22:58 by m_kamal          ###   ########.fr       */
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

t_fdf	*init_fdf(char *filename, int w, int h)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		err_hndl("Can't Initialize FdF.");
	fdf->map = map_read(filename);
	fdf->map->matrix = map_fill(filename, fdf->map,
			fdf->map->x_max, fdf->map->y_max);
	if (!fdf->map)
	{
		err_hndl("Can't Parse map.");
		free(fdf);
	}
	fdf->win = new_win(w, h);
	fdf->img = new_img(w, h, fdf->win);
	if (!fdf->img)
		free_matrix(fdf->map);
	return (fdf);
}

void	mlx_to_do(t_win *win, t_img *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->m_win, img->img_ptr, x, y);
	mlx_hook(win->m_win, 17, 0, &exit_window, win);
	mlx_key_hook(win->m_win, &key_parse, win);
	mlx_loop(win->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;
	t_pixel	p0;
	t_pixel	p1;
	t_line	line;

	p0.x = 0;
	p0.y = 0;
	p1.x = 50;
	p1.y = 867;
	line.start = p0;
	line.end = p1;
	if (argc != 2)
		err_hndl("Please enter a valid map path");
	file_name = argv[1];
	fdf = init_fdf(file_name, 1200, 900);
	// render;
	draw_line(fdf->img, &line, TEXT_COLOR);
	mlx_to_do(fdf->win, fdf->img, 0, 0);
}
