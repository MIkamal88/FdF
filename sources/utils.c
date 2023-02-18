/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:40:33 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/18 16:06:29 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	swap_points(t_pixel *p0, t_pixel *p1)
{
	int	tmp;
	int	tmp2;

	tmp = p0->x;
	p0->x = p1->x;
	p1->x = tmp;
	tmp2 = p0->y;
	p0->y = p1->y;
	p1->y = tmp2;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y_max)
		free(map->matrix[i++]);
	free(map->matrix);
	free(map);
}

void	free_all(t_fdf *fdf)
{
	free_map(fdf->map);
	mlx_destroy_image(fdf->win->mlx, fdf->img->img_ptr);
	free(fdf->cam);
	free(fdf->img);
	mlx_destroy_window(fdf->win->mlx, fdf->win->m_win);
	free(fdf->win->mlx);
	free(fdf->win);
	free(fdf);
}
