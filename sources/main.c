/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/30 22:57:56 by mshehata         ###   ########.fr       */
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

int	main(void)
{
	t_win		fdf;
	t_img		img3;
	t_coords	p0;
	t_coords	p1;
	t_line		line;

	p0.x = 450;
	p0.y = 540;
	p1.x = 50;
	p1.y = 50;
	line.start = p0;
	line.end = p1;
	fdf = new_window(1920, 1080, "FdF");
	if (!fdf.mlx || !fdf.mlx_win)
		exit(EXIT_FAILURE);
	img3 = new_img(1920, 1080, fdf);
	draw_line(&img3, line, TEXT_COLOR);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img3.img_ptr, 0, 0);
	mlx_hook(fdf.mlx_win, 17, 0, exit_window, &fdf);
	mlx_key_hook(fdf.mlx_win, key_parse, &fdf);
	mlx_loop(fdf.mlx);
}
