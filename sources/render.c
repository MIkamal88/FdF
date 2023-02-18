/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:28:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/18 10:01:58 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	render_line(t_fdf *fdf, t_pixel p0, t_pixel p1)
{
	fdf->img->line = start_line(p0, p1, fdf->img->line_color);
	if (!fdf->img->line)
		err_hndl("Failed to render.");
	projection(fdf->cam, fdf->img->line);
	cam_pov(fdf->cam, fdf->img->line);
	draw_line(fdf->img, fdf->img->line);
	free(fdf->img->line);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (y > data->h || x > data->w || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render(t_fdf *fdf, int color)
{
	int	x;
	int	y;

	fdf->img->line_color = color;
	y = 0;
	while (y < fdf->map->y_max)
	{
		x = 0;
		while (x < fdf->map->x_max)
		{
			if (x < (fdf->map->x_max - 1))
				render_line(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y][x + 1]);
			if (y < (fdf->map->y_max - 1))
				render_line(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->win->mlx, fdf->win->m_win,
		fdf->img->img_ptr, 0, 0);
	print_text(fdf);
}
