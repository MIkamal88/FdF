/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/20 21:37:11 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../includes/keybinds.h"

static void	move_cam(int key, t_fdf *fdf)
{
	if (key == KEY_RIGHT)
		fdf->cam->move_x += 10;
	else if (key == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (key == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (key == KEY_UP)
		fdf->cam->move_y -= 10;
}

static void	zoom_cam(int key, t_fdf *fdf)
{
	if (key == KEY_I)
		fdf->cam->zoom += 5;
	if (key == KEY_O)
	{
		if (fdf->cam->zoom == 5)
			return ;
		else
			fdf->cam->zoom -= 5;
	}
}

int	exit_window(t_fdf *fdf)
{
	if (fdf->win)
		free_all(fdf);
	exit(EXIT_SUCCESS);
}

int	key_parse(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	if (key == NUMKEY_1)
		fdf->cam->projection = ISOMETRIC;
	if (key == NUMKEY_2)
		fdf->cam->projection = TOPVIEW;
	if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP \
		|| key == KEY_DOWN)
		move_cam(key, fdf);
	if (key == KEY_I || key == KEY_O)
		zoom_cam(key, fdf);
	if (key == KEY_R)
		reset_cam(fdf);
	ft_bzero(fdf->img->addr, IMG_SIZE * 4);
	render(fdf, TEXT_COLOR);
	return (0);
}
