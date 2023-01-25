/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:26 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/25 16:05:07 by mshehata         ###   ########.fr       */
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
	int		height;
	int		width;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_length;
}	t_img;

typedef struct s_coords {
	int	x_coord;
	int	y_coord;
}	t_coords;

void	pixel_put(t_img *data, int x, int y, int color);
void	draw_square(t_img *data, t_coords *dimns, int len, int color);
int		exit_window(t_win *window);
int		exit_window2(int key, t_win *window);

#endif
