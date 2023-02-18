/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/18 06:55:35 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
// # include "../mlx_mac/mlx.h"

# define WINDOW_WIDTH	1600
# define WINDOW_HEIGHT	900
# define IMG_SIZE		1440000
# define ISOMETRIC		1
# define TOPVIEW		2
# define ANG_30			0.52359816

typedef struct s_pixel {
	float	x;
	float	y;
	float	z;
}	t_pixel;

typedef struct s_line {
	t_pixel	start;
	t_pixel	end;
	int		dx;
	int		dy;
	int		decision;
	int		color;
}	t_line;

typedef struct s_win
{
	void	*mlx;
	void	*m_win;
	int		width;
	int		height;
}	t_win;

typedef struct s_img
{
	t_line	*line;
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_length;
	int		line_color;
}	t_img;

typedef struct s_cam
{
	int	projection;
	int	move_x;
	int	move_y;
	int	zoom;
}	t_cam;

typedef struct s_map {
	t_pixel	**matrix;
	int		x_max;
	int		y_max;
}	t_map;

typedef struct s_fdf
{
	t_win	*win;
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
}	t_fdf;

t_map	*map_read(char *filename);
t_pixel	**map_fill(char *file_name, t_map *map, int x_max, int y_max);
t_line	*start_line(t_pixel p0, t_pixel p1, int color);
t_cam	*init_cam(t_map	*map);
void	render(t_fdf *fdf, int color);
void	projection(t_cam *cam, t_line *line);
void	cam_pov(t_cam *cam, t_line *line);
int		ft_abs(int n);
void	swap_points(t_pixel *p0, t_pixel *p1);
void	draw_line(t_img *img, t_line *line);
void	pixel_put(t_img *data, int x, int y, int color);
int		exit_window(t_fdf *fdf);
int		key_parse(int key, t_fdf *fdf);
void	reset_cam(t_fdf *fdf);
void	free_map(t_map *map);
void	free_all(t_fdf *fdf);
void	err_hndl(char *err);
// void	draw_line2(t_img *img, t_line *line);

#endif
