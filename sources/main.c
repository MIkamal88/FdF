/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:01:35 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/20 15:29:08 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *data, t_coords *dimns, int len, int color)
{
	while (dimns->x_coord++ <= len)
		my_mlx_pixel_put(data, dimns->x_coord, dimns->y_coord, color);
	while (dimns->y_coord++ <= len)
		my_mlx_pixel_put(data, dimns->x_coord, dimns->y_coord, color);
	while (dimns->x_coord-- >= 15)
		my_mlx_pixel_put(data, dimns->x_coord, dimns->y_coord, color);
	while (dimns->y_coord-- >= 15)
		my_mlx_pixel_put(data, dimns->x_coord, dimns->y_coord, color);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_coords	coords;

	coords.x_coord = 15;
	coords.y_coord = 15;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 900, "FdF");
	img.img = mlx_new_image(mlx, 1600, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_square(&img, &coords, 500, SQUARE_COLOR);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
