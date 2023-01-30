/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:11:30 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/30 12:23:32 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	draw_line(t_img *img, t_line line, int color)
{
	t_coords	pixel;
	int			p;

	pixel.x = line.start.x;
	pixel.y = line.start.y;
	p = 2 * (line.dy - line.dx);
	while (pixel.x < line.end.x)
	{
		if (p >= 0)
		{
			pixel_put(img, pixel.x, pixel.y, color);
			pixel.y++;
			p = p + 2 * line.dy - 2 * line.dx;
		}
		else
		{
			pixel_put(img, pixel.x, pixel.y, color);
			p = p + 2 * line.dy;
		}
		pixel.x++;
	}
}
