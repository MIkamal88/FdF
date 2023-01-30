/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:18:34 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/30 10:08:46 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_swap(t_line line)
{
	int	tmp;

	if (line.dx < line.dy)
	{
		tmp = line.dx;
		line.dx = line.dy;
		line.dy = tmp;
		return (1);
	}
	return (0);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	draw_line(t_img *img, t_line line, int color)
{
	int		i;
	int		swap;

	line.dx = ft_abs(line.end.x - line.start.x);
	line.dy = ft_abs(line.end.y - line.start.y);
	line.s1 = get_sign(line.end.x - line.start.x);
	line.s2 = get_sign(line.end.y - line.start.y);
	swap = ft_swap(line);
	line.decision = 2 * line.dy - line.dx;
	i = 0;
	while (i < line.dx)
	{
		pixel_put(img, line.start.x, line.start.y, color);
		while (line.decision >= 0)
		{
			line.decision -= (2 * line.dx);
			line.start.x += (line.s1 * swap);
			line.start.y += (line.s2 * !swap);
		}
		line.decision += (2 * line.dy);
		line.start.y += (line.s2 * swap);
		line.start.x += (line.s1 * !swap);
		i++;
	}
}
