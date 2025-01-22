/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:23:21 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/23 11:31:06 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static double	calculate_tex_pos(int draw_start, int line_height)
{
	return ((draw_start - SCREEN_HEIGHT / 2 + line_height / 2) \
	* (1.0 * TEX_HEIGHT / line_height));
}

static int	ft_get_texture_color(t_ray *ray, t_cub *cub, int tex_x, int tex_y)
{
	if (ray->hit == 2)
		return (cub->map->texture->door->tex[tex_x][tex_y]);
	else
	{
		if (ray->side == 1)
			return (cub->map->texture->east->tex[tex_x][tex_y]);
		else if (ray->side == 0)
			return (cub->map->texture->south->tex[tex_x][tex_y]);
		else if (ray->side == 2)
			return (cub->map->texture->north->tex[tex_x][tex_y]);
		else if (ray->side == 3)
			return (cub->map->texture->west->tex[tex_x][tex_y]);
	}
	return (0);
}

static void	ft_fill_buffer_line(t_column *column, t_ray *ray, \
t_cub *cub, double step)
{
	double	tex_pos;	
	int		tex_y;
	int		color;
	int		i;
	int		y;

	i = 0;
	color = 0;
	y = column->draw_start;
	tex_pos = calculate_tex_pos(column->draw_start, column->line_height);
	while (y < column->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = ft_get_texture_color(ray, cub, column->tex_x, tex_y);
		column->buffer[i] = color;
		i++;
		y++;
	}
}

void	ft_fill_buffer(t_column *column, t_ray *ray, t_cub *cub)
{
	double	step;

	step = 1.0 * TEX_HEIGHT / column->line_height;
	ft_fill_buffer_line(column, ray, cub, step);
}
