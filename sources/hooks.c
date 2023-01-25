/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/25 14:44:50 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx, window->mlx_win);
	exit(EXIT_SUCCESS);
}

int	exit_window2(int key, t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx, window->mlx_win);
	exit(EXIT_SUCCESS);
}
