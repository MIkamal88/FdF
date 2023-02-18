/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:30:10 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/18 09:49:44 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	print_text(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 10;
	y = 20;
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y,
		TEXT_COLOR, "Press 'Esc' to close.");
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y += 20,
		TEXT_COLOR, "Press 'I' to zoom in.");
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y += 20,
		TEXT_COLOR, "Press 'O' to zoom out.");
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y += 20,
		TEXT_COLOR, "Press 'R' to reset map.");
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y += 20,
		TEXT_COLOR, "Press '1' for Isometric View.");
	mlx_string_put(fdf->win->mlx, fdf->win->m_win, x, y += 20,
		TEXT_COLOR, "Press '2' for Top View.");
}
