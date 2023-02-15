/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:28:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/15 18:08:50 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	scale_line(t_line *line, int scale)
{
	line->start.x *= scale;
	line->start.y *= scale;
	line->end.x *= scale;
	line->end.y *= scale;
}

static void	render_line(t_fdf *fdf, t_pixel p0, t_pixel p1, int scale)
{
	fdf->img->line = start_line(p0, p1, fdf->img->line_color);
	if (!fdf->img->line)
		err_hndl("Failed to render");
	projection(fdf->cam, fdf->img->line);
	scale_line(fdf->img->line, scale);
	draw_line(fdf->img, fdf->img->line);
	free(fdf->img->line);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (y > data->h || x > data->w)
		err_hndl("Pixel is out of image frame");
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render(t_fdf *fdf, int scale, int color)
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
					fdf->map->matrix[y][x + 1], scale);
			if (y < (fdf->map->y_max - 1))
				render_line(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y + 1][x], scale);
			x++;
		}
		y++;
	}
}
