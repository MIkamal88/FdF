/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:13 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/08 13:33:04 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

// void	draw_grid(t_img *img, t_map map, int step)
// {
// 	t_pixel	p0;
// 	t_pixel	p1;
// 	t_line	line;

// 	p0.x = step;
// 	p0.y = step;
// 	p1 = p0;
// 	line.start = p0;
// 	line.end = p1;
// 	while (line.start.y <= (map.y_max - 1) * step)
// 	{
// 		while (p1.x <= (map.x_max * step))
// 		{
// 			p1.x = p0.x + step;
// 			draw_line(img, p0, p1, TEXT_COLOR);
// 			line.start = p0;
// 			line.end.y += step;
// 			draw_line(img, line.start, line.end, TEXT_COLOR);
// 			p0 = p1;
// 		}
// 		p0.y += step;
// 		p0.x = step;
// 		p1 = p0;
// 	}
// }

// for (j = 0; j < NUM_ROWS; j++)
// {
//    for (k = 0; k < NUM_COLS; k++)
//    {
//       printf("&#37;2c", grid[j][k]);
//    }
//    printf("\n");
// }
		// p1.x += step;
		// p1.y = (map.y_max * step);
		// line.start = p0;
		// line.end = p1;
		// draw_line(img, line, TEXT_COLOR);
		// p1.y = step;
		// p0 = p1;
