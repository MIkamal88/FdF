/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/03 01:36:59 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (y > data->h || x > data->w || x < 0 || y < 0)
		err_hndl("Pixel is out of image frame");
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_win	new_window(int w, int h, char *str)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, w, h, str);
	return ((t_win){mlx, mlx_win, w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	if (h > window.height || w > window.width)
		err_hndl("Image frame is bigger than window");
	image.img_ptr = mlx_new_image(window.mlx, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_length), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int	main(int argc, char **argv)
{
	t_win		fdf;
	t_img		img;
	t_pixel		p0;
	t_pixel		p1;
	t_line		line;
	t_mapsize	map;

	if (argc != 2)
		err_hndl("Please enter a valid map path");
	else
	{
		p0.x = 40;
		p0.y = 40;
		p1.x = 40;
		p1.y = 40;
		line.start = p0;
		line.end = p1;
		map = map_read(argv[1]);
		printf("X = %d\nY = %d\n", map.x, map.y);
		fdf = new_window(1920, 1080, "FdF");
		img = new_img(1920, 1080, fdf);
		draw_grid(&img, map);
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img_ptr, 0, 0);
		mlx_hook(fdf.mlx_win, 17, 0, exit_window, &fdf);
		mlx_key_hook(fdf.mlx_win, key_parse, &fdf);
		mlx_loop(fdf.mlx);
	}
}
