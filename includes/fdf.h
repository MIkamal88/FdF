/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/03 01:33:23 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"
// # include "../mlx_mac/mlx.h"

typedef struct s_window
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

typedef struct s_mapsize {
	int	x;
	int	y;
}	t_mapsize;

typedef struct s_y_width {
	char	*line;
	int		y;
}	t_y_width;

t_img		new_img(int w, int h, t_win window);
void		pixel_put(t_img *data, int x, int y, int color);
t_mapsize	map_read(char *map);
int			get_width(char *line);
t_y_width	get_height(char *map, int fd);
// t_pixel		x_elements(char *line);
// t_pixel		y_elements(char *map, int fd);
// int			get_width(char *line);
// int			get_height(char *map);
void		draw_line(t_img *img, t_line line, int color);
int			ft_abs(int n);
void		draw_grid(t_img *img, t_mapsize map);
// void		draw_square(t_img *data, t_pixel *dimns, int len, int color);
int			exit_window(t_win *window);
int			key_parse(int key, t_win *window);
void		err_hndl(char *err);

#endif
