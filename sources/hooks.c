/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:46 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/10 11:55:05 by m_kamal          ###   ########.fr       */
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

int	key_parse(int key, t_fdf *fdf, t_cam *cam)
{
	if (fdf->win && key == KEY_ESC)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	if (fdf->win && key == 49)
		cam->projection = 1;
	if (fdf->win && key == 50)
		cam->projection = 0;
	return (0);
}
