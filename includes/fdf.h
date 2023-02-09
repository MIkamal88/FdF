/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/09 14:51:55 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
// # include "../mlx_mac/mlx.h"

# define ANG_30	0.5236

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_length;
}	t_img;

typedef struct s_cam
{
	int	projection;
}	t_cam;

enum	e_projection
{
	isometric,
	top
};

typedef struct s_pixel {
	int	x;
	int	y;
	int	z;
}	t_pixel;

typedef struct s_line {
	t_pixel	start;
	t_pixel	end;
	int		dx;
	int		dy;
	int		decision;
}	t_line;

typedef struct s_map {
	t_pixel	**matrix;
	int		x_max;
	int		y_max;
}	t_map;

typedef struct s_y_width {
	char	*line;
	int		y;
}	t_y_width;

typedef struct s_fdf
{
	t_win	win;
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
}	t_fdf;

t_map	*map_read(char *filename);
t_map	*init_map(void);
t_pixel	**map_fill(char *file_name, t_map *map);
t_line	*start_line(t_img *img, t_pixel p0, t_pixel p1, int color);
void	pixel_put(t_img *data, int x, int y, int color);
void	render(t_fdf *fdf, int scale);
int		exit_window(t_win *window);
int		key_parse(int key, t_win *window, t_cam *cam);
int		ft_abs(int n);
void	swap_points(t_pixel *p0, t_pixel *p1);
void	free_map(t_fdf	*fdf);
void	free_matrix(t_map *map);
void	err_hndl(char *err);

#endif
