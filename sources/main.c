/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/27 14:29:07 by m_kamal          ###   ########.fr       */
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
	t_img		img3;
	t_coords	coords;
	t_coords	coords2;
	t_line		line;

	line.start = coords;
	line.end = coords2;
	coords.x = 15;
	coords.y = 15;
	coords2.x = 565;
	coords2.y = 565;
	fdf = new_window(1600, 900, "FdF");
	if (!fdf.mlx || !fdf.mlx_win)
		exit(EXIT_FAILURE);
	img = new_img(300, 300, fdf);
	img2 = new_img(100, 100, fdf);
	img3 = new_img(600, 600, fdf);
	draw_square(&img, &coords, 200, SQUARE_COLOR);
	draw_square(&img2, &coords, 50, TEXT_COLOR);
	draw_line(&img3, line, TEXT_COLOR);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img_ptr, 0, 0);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img2.img_ptr, 202, 202);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img3.img_ptr, 500, 500);
	mlx_hook(fdf.mlx_win, 17, 0, exit_window, &fdf);
	mlx_key_hook(fdf.mlx_win, key_parse, &fdf);
	mlx_loop(fdf.mlx);
}
