/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:04 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/16 14:51:27 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_line	*start_line(t_pixel p0, t_pixel p1, int color)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = p0.x;
	line->start.y = p0.y;
	line->start.z = p0.z;
	line->end.x = p1.x;
	line->end.y = p1.y;
	line->end.z = p1.z;
	line->decision = 0;
	line->dx = 0;
	line->dy = 0;
	line->color = color;
	return (line);
}

static void	plotline_low(t_img *img, t_line *line)
{
	t_pixel	pixel;
	int		yi;

	pixel = line->start;
	line->dx = line->end.x - line->start.x;
	line->dy = line->end.y - line->start.y;
	yi = 1;
	if (line->dy < 0)
	{
		yi = -1;
		line->dy = line->dy * (-1);
	}
	line->decision = (2 * line->dy) - line->dx;
	while (pixel.x < line->end.x)
	{
		pixel_put(img, pixel.x, pixel.y, line->color);
		if (line->decision > 0)
		{
			pixel.y = pixel.y + yi;
			line->decision = line->decision + (2 * (line->dy - line->dx));
		}
		else
			line->decision = line->decision + 2 * line->dy;
		pixel.x++;
	}
}

static void	plotline_high(t_img *img, t_line *line)
{
	t_pixel	pixel;
	int		xi;

	pixel = line->start;
	line->dx = line->end.x - line->start.x;
	line->dy = line->end.y - line->start.y;
	xi = 1;
	if (line->dx < 0)
	{
		xi = -1;
		line->dx = -(line->dx);
	}
	line->decision = (2 * line->dx) - line->dy;
	while (pixel.y < line->end.y)
	{
		pixel_put(img, pixel.x, pixel.y, line->color);
		if (line->decision > 0)
		{
			pixel.x = pixel.x + xi;
			line->decision = line->decision + (2 * (line->dx - line->dy));
		}
		else
			line->decision = line->decision + 2 * line->dx;
		pixel.y++;
	}
}

void	draw_line(t_img *img, t_line *line)
{
	line->dx = line->end.x - line->start.x;
	line->dy = line->end.y - line->start.y;
	if (ft_abs(line->dy) < ft_abs(line->dx))
	{
		if (line->start.x > line->end.x)
		{
			swap_points(&line->start, &line->end);
			plotline_low(img, line);
		}
		else
			plotline_low(img, line);
	}
	else
	{
		if (line->start.y > line->end.y)
		{
			swap_points(&line->start, &line->end);
			plotline_high(img, line);
		}
		else
			plotline_high(img, line);
	}
}

void	draw_line2(t_img *img, t_line *line)
{
	t_pixel	pixel;
	float	steps;
	float	x_increment;
	float	y_increment;
	int		i;

	i = 0;
	pixel = line->start;
	line->dx = line->end.x - line->start.x;
	line->dy = line->end.y - line->start.y;
	line->dx = ft_abs(line->dx);
	line->dy = ft_abs(line->dy);
	if (line->dx >= line->dy)
		steps = line->dx;
	else
		steps = line->dy;
	x_increment = (line->dx) / steps;
	y_increment = (line->dy) / steps;
	while (i < steps)
	{
		pixel_put(img, pixel.x, pixel.y, line->color);
		pixel.x += x_increment;
		pixel.y += y_increment;
		i++;
	}
}
