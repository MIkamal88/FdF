/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:13 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/03 14:07:26 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	draw_grid(t_img *img, t_mapsize map)
{
	t_pixel	p0;
	t_pixel	p1;
	t_line	line;

	p0.x = 10;
	p0.y = 10;
	p1.x = p0.x;
	p1.y = p0.y;
	line.start = p0;
	line.end = p1;
	while (p1.x <= map.x)
	{
		while (map.x % p1.x == 0)
		{
			line.start = p0;
			line.end = p1;
			draw_line(img, line, TEXT_COLOR);
			p1.y += 10;
		}
		p1.x += 10;
	}
}
