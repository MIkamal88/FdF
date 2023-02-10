/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:04 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/10 10:45:19 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

t_line	*start_line(t_img *img, t_pixel p0, t_pixel p1, int color)
{
	t_line	*line;

	line = malloc(sizeof(line));
	if (!line)
		return (NULL);
	line->start.x = p0.x;
	line->start.y = p0.y;
	line->end.x = p1.x;
	line->end.y = p1.y;
	return (line);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (y > data->h || x > data->w || x < 0 || y < 0)
		err_hndl("Pixel is out of image frame");
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	plotline_low(t_img *img, t_line *line, int color)
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
		pixel_put(img, pixel.x, pixel.y, color);
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

static void	plotline_high(t_img *img, t_line *line, int color)
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
		pixel_put(img, pixel.x, pixel.y, color);
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

void	draw_line(t_img *img, t_line *line, int color)
{
	line->dx = line->end.x - line->start.x;
	line->dy = line->end.y - line->start.y;
	if (ft_abs(line->dy) < ft_abs(line->dx))
	{
		if (line->start.x > line->end.x)
		{
			swap_points(&line->start, &line->end);
			plotline_low(img, line, color);
		}
		else
			plotline_low(img, line, color);
	}
	else
	{
		if (line->start.y > line->end.y)
		{
			swap_points(&line->start, &line->end);
			plotline_high(img, line, color);
		}
		else
			plotline_high(img, line, color);
	}
}
