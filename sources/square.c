/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:13 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/04 18:33:11 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	draw_grid(t_img *img, t_mapsize map, int step)
{
	t_pixel	p0;
	t_pixel	p1;
	t_line	line;

	p0.x = step;
	p0.y = step;
	p1 = p0;
	while (p1.x <= (map.x * step))
	{
		p1.x += step;
		line.start = p0;
		line.end = p1;
		draw_line(img, line, TEXT_COLOR);
		// while loop for y here
		p0 = p1;
	}
	p1.y += step;
}

// for (j = 0; j < NUM_ROWS; j++)
// {
//    for (k = 0; k < NUM_COLS; k++)
//    {
//       printf("&#37;2c", grid[j][k]);
//    }
//    printf("\n");
// }
