/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/06 16:06:37 by mshehata         ###   ########.fr       */
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
	t_win	fdf;
	t_img	img;
	t_line	line;
	t_map	map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 2)
		err_hndl("Please enter a valid map path");
	else
	{
		map = map_read(argv[1]);
		printf("X = %d\nY = %d\n", map.x_max, map.y_max);
		while (j < map.y_max)
		{
			while (i < map.x_max)
			{
				printf("pix.X = %d\npix.Y = %d\n", map.matrix[i][j].x, map.matrix[i][j].y);
				i++;
			}
			i = 0;
			j++;
		}
		fdf = new_window(1920, 1080, "FdF");
		img = new_img(1920, 1080, fdf);
		// draw_grid(&img, map, 30);
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img_ptr, 0, 0);
		mlx_hook(fdf.mlx_win, 17, 0, exit_window, &fdf);
		mlx_key_hook(fdf.mlx_win, key_parse, &fdf);
		mlx_loop(fdf.mlx);
	}
}
