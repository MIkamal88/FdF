/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:28:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/11 12:22:59 by m_kamal          ###   ########.fr       */
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

//Handle colors
static void	render_line(t_fdf *fdf, t_pixel p0, t_pixel p1, float scale)
{
	int	scale2;

	scale2 = (int)(scale * 10) % 10;
	scale2 = scale2 * 10;
	fdf->img->line = start_line(p0, p1);
	if (!fdf->img->line)
		err_hndl("Failed to render");
	// projection(fdf->cam, fdf->img->line);
	scale_line(fdf->img->line, scale2);
	draw_line(fdf->img, fdf->img->line, TEXT_COLOR);
	free(fdf->img->line);
}

void	render(t_fdf *fdf, float scale, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->y_max)
	{
		x = 0;
		while (x < fdf->map->x_max)
		{
			if (x < fdf->map->x_max - 1)
				render_line(fdf, fdf->map->matrix[x][y],
					fdf->map->matrix[x + 1][y], scale);
			if (y < fdf->map->y_max - 1)
				render_line(fdf, fdf->map->matrix[x][y],
					fdf->map->matrix[x][y + 1], scale);
			x++;
		}
		y++;
	}
}
