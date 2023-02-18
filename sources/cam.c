/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:48:14 by m_kamal           #+#    #+#             */
/*   Updated: 2023/02/18 18:00:48 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	scale_line(t_line *line, int scale)
{
	line->start.x *= scale;
	line->start.y *= scale;
	line->end.x *= scale;
	line->end.y *= scale;
}

static void	move(t_line *line, int move_x, int move_y)
{
	line->start.x += move_x;
	line->start.y += move_y;
	line->end.x += move_x;
	line->end.y += move_y;
}

void	cam_pov(t_cam *cam, t_line *line)
{
	scale_line(line, cam->zoom);
	move(line, cam->move_x, cam->move_y);
}

t_cam	*init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->zoom = 15;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	return (cam);
}

void	reset_cam(t_fdf *fdf)
{
	fdf->cam->projection = ISOMETRIC;
	fdf->cam->zoom = 15;
	fdf->cam->move_x = WINDOW_WIDTH / 2;
	fdf->cam->move_y = WINDOW_HEIGHT / 2;
}
