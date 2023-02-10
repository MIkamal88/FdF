/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:28:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/09 16:51:29 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	render_line(t_fdf *fdf, t_pixel p0, t_pixel p1, int scale)
{
	scale = ((scale * 10) % 10) * 10;

}

void	render(t_fdf *fdf, int scale)
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
