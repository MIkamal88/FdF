/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/09 11:22:27 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../includes/keybinds.h"

int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx, window->mlx_win);
	exit(EXIT_SUCCESS);
}

int	key_parse(int key, t_win *window, t_cam *cam)
{
	if (window && key == KEY_ESC)
	{
		mlx_destroy_window (window->mlx, window->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (window && key == 49)
		cam->projection = 1;
	if (window && key == 50)
		cam->projection = 0;
	return (0);
}
