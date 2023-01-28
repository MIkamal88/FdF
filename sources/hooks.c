/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/26 14:02:33 by m_kamal          ###   ########.fr       */
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

int	key_parse(int key, t_win *window)
{
	if (window && key == KEY_ESC)
	{
		mlx_destroy_window (window->mlx, window->mlx_win);
		exit(EXIT_SUCCESS);
	}
}
