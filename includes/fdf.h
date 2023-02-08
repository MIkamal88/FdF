/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/08 13:42:45 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
// # include "../mlx_linux/mlx.h"
# include "../mlx_mac/mlx.h"

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

t_img		new_img(int w, int h, t_win *window);
void		pixel_put(t_img *data, int x, int y, int color);
int			get_height(int fd);
t_map		map_read(char *map);
void		fill_row(t_map *map, char *line, int y);
int			get_z_coord(char *line, int i, int x_max);
t_pixel		**map_fill(char *file_name, t_map *map);
void		d_line(t_img *img, t_pixel p0, t_pixel p1, int color);
void		draw_line(t_img *img, t_line line, int color);
// void		draw_grid(t_img *img, t_map map, int step);
int			exit_window(t_win *window);
int			key_parse(int key, t_win *window);
int			ft_abs(int n);
int			count_words(char const *str, char c);
void		err_hndl(char *err);

#endif
