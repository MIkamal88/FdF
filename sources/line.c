/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:12 by m_kamal           #+#    #+#             */
/*   Updated: 2023/01/27 17:11:53 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

// void	swap(int x0, int x1)
// {
// 	int	tmp;

// 	if (x0 > x1)
// 	{
// 		tmp = x0;
// 		x0 = x1;
// 		x1 = tmp;
// 	}
// }

void	draw_line(t_img *img, t_line line, int color)
{
	int		a;
	float	x;
	float	y;

	if (line.start.x > line.end.x)
	{
		line.start.x = line.start.x + line.end.x;
		line.end.x = line.start.x - line.end.x;
		line.start.x = line.start.x - line.end.x;
	}
	x = line.start.x;
	a = (line.end.y - line.start.y)
		/ (line.end.x - line.start.x);
	y = line.start.y;
	while (x <= line.end.x)
	{
		pixel_put(img, x, y, color);
		y = y + a;
		x++;
	}
}

// int main(void)
// {
// 	int x0 = 15;
// 	int x1 = 10;

// 	swap(x0, x1);
// 	printf("%d\n%d\n", x0, x1);
// }
