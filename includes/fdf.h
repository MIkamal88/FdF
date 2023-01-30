/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/30 10:14:58 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
// # include "../mlx_linux/mlx.h"
# include "../mlx_mac/mlx.h"

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

typedef struct s_coords {
	int	x;
	int	y;
}	t_coords;

typedef struct s_line {
	t_coords	start;
	t_coords	end;
	int			dx;
	int			dy;
	int			s1;
	int			s2;
	int			decision;
}	t_line;

t_img	new_img(int w, int h, t_win window);
void	pixel_put(t_img *data, int x, int y, int color);
void	draw_line(t_img *img, t_line line, int color);
void	swap_base_x(t_coords *p0, t_coords *p1);
void	swap_base_y(t_coords *p0, t_coords *p1);
void	draw_square(t_img *data, t_coords *dimns, int len, int color);
int		exit_window(t_win *window);
int		key_parse(int key, t_win *window);
void	err_hndl(char *err);

#endif
