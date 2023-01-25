/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:13 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/25 13:29:59 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	draw_square(t_img *data, t_coords *dimns, int len, int color)
{
	while (dimns->x_coord <= len)
	{
		pixel_put(data, dimns->x_coord, dimns->y_coord, color);
		dimns->x_coord++;
	}
	while (dimns->y_coord <= len)
	{
		pixel_put(data, dimns->x_coord, dimns->y_coord, color);
		dimns->y_coord++;
	}
	while (dimns->x_coord >= 15)
	{
		pixel_put(data, dimns->x_coord, dimns->y_coord, color);
		dimns->x_coord--;
	}
	while (dimns->y_coord >= 15)
	{
		pixel_put(data, dimns->x_coord, dimns->y_coord, color);
		dimns->y_coord--;
	}
}
