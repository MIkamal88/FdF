/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:13 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/02 12:02:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	draw_square(t_img *data, t_pixel *dimns, int len, int color)
{
	while (dimns->x <= len)
	{
		pixel_put(data, dimns->x, dimns->y, color);
		dimns->x++;
	}
	while (dimns->y <= len)
	{
		pixel_put(data, dimns->x, dimns->y, color);
		dimns->y++;
	}
	while (dimns->x >= 15)
	{
		pixel_put(data, dimns->x, dimns->y, color);
		dimns->x--;
	}
	while (dimns->y >= 15)
	{
		pixel_put(data, dimns->x, dimns->y, color);
		dimns->y--;
	}
}
