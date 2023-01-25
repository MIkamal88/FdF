/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/25 14:45:27 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

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
	t_img		img;
	t_img		img2;
	t_coords	coords;

	coords.x_coord = 15;
	coords.y_coord = 15;
	fdf = new_window(1600, 900, "FdF");
	if (!fdf.mlx || !fdf.mlx_win)
		exit(EXIT_FAILURE);
	img = new_img(300, 300, fdf);
	img2 = new_img(100, 100, fdf);
	draw_square(&img, &coords, 200, SQUARE_COLOR);
	draw_square(&img2, &coords, 50, TEXT_COLOR);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img_ptr, 0, 0);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img2.img_ptr, 202, 202);
	mlx_hook(fdf.mlx_win, 17, 0, exit_window, &fdf);
	mlx_hook(fdf.mlx_win, 2, 1L << 0, exit_window2, &fdf);
	mlx_loop(fdf.mlx);
}
