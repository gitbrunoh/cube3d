/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:45 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/02 18:31:33 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_draw_vertical_line(int x, t_column *column, t_cub *cub)
{
	int	color;
	int	i;

	i = 0;
	while (i < column->draw_start)
		ft_my_mlx_pixel_put(cub, x, i++, cub->map->texture->ceiling->color);
	i = 0;
	while (column->draw_start < column->draw_end)
	{
		color = column->buffer[i];
		ft_my_mlx_pixel_put(cub, x, column->draw_start, color);
		column->draw_start++;
		i++;
	}
	while (column->draw_end < SCREEN_HEIGHT)
		ft_my_mlx_pixel_put(cub, x, column->draw_end++, \
		cub->map->texture->floor->color);
}

static int	**allocate_pixel_memory(int width, int height)
{
	int	**pixels;
	int	x;

	pixels = malloc(width * sizeof(int *));
	if (!pixels)
		return (NULL);
	x = 0;
	while (x < width)
	{
		pixels[x] = malloc(height * sizeof(int));
		if (!pixels[x])
		{
			while (--x >= 0)
				free(pixels[x]);
			free(pixels);
			return (NULL);
		}
		x++;
	}
	return (pixels);
}

int	**ft_get_image_pixels(t_img *img, int w, int h)
{
	int	**pixels;
	int	x;
	int	y;

	pixels = allocate_pixel_memory(w, h);
	if (!pixels)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": int** pixels", "\"\n"), 1);
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			pixels[x][y] = *(int *)(img->data + y * img->size_line \
			+ x * (img->bpp / 8));
			x++;
		}
		y++;
	}
	return (pixels);
}
