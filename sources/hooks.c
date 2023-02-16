/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/16 10:26:13 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../includes/keybinds.h"

int	exit_window(t_fdf *fdf)
{
	if (fdf->win)
		free_all(fdf);
	exit(EXIT_SUCCESS);
}

int	key_parse(int key, t_fdf *fdf)
{
	if (fdf->win && key == KEY_ESC)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	// if (fdf->win && key == 125)
	// 	fdf->cam->projection = 1;
	// if (fdf->win && key == 126)
	// 	fdf->cam->projection = 0;
	// render(fdf, 15, TEXT_COLOR);
	return (0);
}
