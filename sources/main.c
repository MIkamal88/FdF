/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/09 14:50:44 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_img	*new_img(int w, int h, t_win *window)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->win = *window;
	if (h > window->height || w > window->width)
		err_hndl("Image frame is bigger than window");
	image->img_ptr = mlx_new_image(window->mlx, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_length), &(image->endian));
	image->w = w;
	image->h = h;
	return (image);
}

t_fdf	*init_fdf(char *filename)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		err_hndl("Can't Initialize FdF.");
	map_read(filename);
	fdf->map->matrix = map_fill(filename, fdf->map);
	if (!fdf->map)
	{
		err_hndl("Can't Parse map.");
		free(fdf);
	}
	fdf->win.mlx = mlx_init();
	fdf->win.mlx_win = mlx_new_window(fdf->win.mlx, 1200, 900, "FdF");
	fdf->img = new_img(1200, 900, &fdf->win);
	if (!fdf->img)
		free_map(fdf);
}

void	mlx_to_do(t_win *win, t_img *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, img->img_ptr, x, y);
	mlx_hook(win->mlx_win, 17, 0, exit_window, win);
	mlx_key_hook(win->mlx_win, key_parse, win);
	mlx_loop(win->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;

	if (argc != 2)
		err_hndl("Please enter a valid map path");
	file_name = argv[1];
	fdf = init_fdf(file_name);

	mlx_to_do(&fdf->win, fdf->img, 0, 0);
}
