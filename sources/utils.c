/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:40:33 by mshehata          #+#    #+#             */
/*   Updated: 2023/02/06 14:37:27 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

t_pixel	**init_coords(int height, int width)
{
	t_pixel	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_pixel *));
	i = 0;
	if (!coordinates)
		return (NULL);
	while (i < width)
	{
		coordinates[i] = malloc(height * sizeof(t_pixel));
		if (!coordinates)
			return (NULL);
		j = 0;
		while (j < height)
		{
			coordinates[i][j].x = i;
			coordinates[i][j].y = j;
			coordinates[i][j].z = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}
