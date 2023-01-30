/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:04 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/30 22:55:11 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static void	swap_base(t_coords *p0, t_coords *p1)
{
	int	tmp;
	int	tmp2;

	tmp = p0->x;
	p0->x = p1->x;
	p1->x = tmp;
	tmp2 = p0->y;
	p0->y = p1->y;
	p1->y = tmp2;
}

static void	plotline_low(t_img *img, t_line line, int color)
{
	t_coords	pixel;
	int			yi;

	pixel = line.start;
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	yi = 1;
	if (line.dy < 0)
	{
		yi = -1;
		line.dy = line.dy * (-1);
	}
	line.decision = (2 * line.dy) - line.dx;
	while (pixel.x < line.end.x)
	{
		pixel_put(img, pixel.x, pixel.y, color);
		if (line.decision > 0)
		{
			pixel.y = pixel.y + yi;
			line.decision = line.decision + (2 * (line.dy - line.dx));
		}
		else
			line.decision = line.decision + 2 * line.dy;
		pixel.x++;
	}
}

static void	plotline_high(t_img *img, t_line line, int color)
{
	t_coords	pixel;
	int			xi;

	pixel = line.start;
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	xi = 1;
	if (line.dx < 0)
	{
		xi = -1;
		line.dx = -(line.dx);
	}
	line.decision = (2 * line.dx) - line.dy;
	while (pixel.y < line.end.y)
	{
		pixel_put(img, pixel.x, pixel.y, color);
		if (line.decision > 0)
		{
			pixel.x = pixel.x + xi;
			line.decision = line.decision + (2 * (line.dx - line.dy));
		}
		else
			line.decision = line.decision + 2 * line.dx;
		pixel.y++;
	}
}

void	draw_line(t_img *img, t_line line, int color)
{
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	if (ft_abs(line.dy) < ft_abs(line.dx))
	{
		if (line.start.x > line.end.x)
		{
			swap_base(&line.start, &line.end);
			plotline_low(img, line, color);
		}
		else
			plotline_low(img, line, color);
	}
	else
	{
		if (line.start.y > line.end.y)
		{
			swap_base(&line.start, &line.end);
			plotline_high(img, line, color);
		}
		else
			plotline_high(img, line, color);
	}
}
