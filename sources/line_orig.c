/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:12 by m_kamal           #+#    #+#             */
/*   Updated: 2023/01/30 11:42:58 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	swap_base_x(t_coords *p0, t_coords *p1)
{
	int	tmp;
	int	tmp2;

	if (p0->x > p1->x)
	{
		tmp = p0->x;
		p0->x = p1->x;
		p1->x = tmp;
		tmp2 = p0->y;
		p0->y = p1->y;
		p1->y = tmp2;
	}
}

void	swap_base_y(t_coords *p0, t_coords *p1)
{
	int	tmp;

	if (p0->y > p1->y)
	{
		tmp = p0->x;
		p0->x = p1->x;
		p1->x = tmp;
		tmp = p0->y;
		p0->y = p1->y;
		p1->y = tmp;
	}
}

/*
(dy * x) - (dx * y) + ((dx) * b)
						x1y0 - x0y1
*/
void	draw_line(t_img *img, t_line line, int color)
{
	t_coords	pixel;
	int			a;

	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	if (abs(line.dx) > abs(line.dy))
	{
		if (line.start.x > line.end.x)
			swap_base_x(&line.start, &line.end);
		pixel.x = line.start.x;
		a = line.dy / line.dy;
		pixel.y = line.start.y;
		while (pixel.x <= line.end.x)
		{
			pixel_put(img, pixel.x, pixel.y, color);
			pixel.y = pixel.y + a;
			pixel.x++;
		}
	}
	else
	{
		if (line.start.y > line.end.y)
			swap_base_y(&line.start, &line.end);
		pixel.x = line.start.x;
		a = line.dy / line.dx;
		pixel.y = line.start.y;
		while (pixel.y <= line.end.y)
		{
			pixel_put(img, pixel.x, pixel.y, color);
			pixel.x = pixel.x + a;
			pixel.y++;
		}
	}
}

// void	drawline(int x0, int y0, int x1, int y1)
// {
// 	int dx, dy, p, x, y;

// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x0;
// 	y = y0;
// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			pixel_put(x, y, color);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			pixel_put(x, y, color);
// 			p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }
