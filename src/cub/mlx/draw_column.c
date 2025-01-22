/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:26 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:11:44 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_calculate_ray_and_distances(int x, t_ray *ray, \
t_player *player, t_cub *cub)
{
	calculate_ray_direction(x, ray, player);
	calculate_initial_distances(player, ray);
	ft_perform_dda(cub, ray);
}

static double	ft_calculate_orto_wall_dist(t_ray *ray)
{
	if (ray->side == 0 || ray->side == 2)
		return (ray->sidedist_x - ray->deltadist_x);
	else
		return (ray->sidedist_y - ray->deltadist_y);
}

static void	ft_calculate_line_params(double orto_wall_dist, int *line_height, \
int *draw_start, int *draw_end)
{
	*line_height = (int)(SCREEN_HEIGHT / orto_wall_dist);
	*draw_start = -(*line_height) / 2 + SCREEN_HEIGHT / 2;
	*draw_end = *line_height / 2 + SCREEN_HEIGHT / 2;
}

static int	ft_calculate_tex_x(t_ray *ray, t_player *player, \
double orto_wall_dist)
{
	double	wall_cord;
	int		tex_x;

	if (ray->side == 0 || ray->side == 2)
		wall_cord = player->p_y + orto_wall_dist * ray->dir_y;
	else
		wall_cord = player->p_x + orto_wall_dist * ray->dir_x;
	wall_cord -= floor((wall_cord));
	tex_x = (int)(wall_cord * (double)TEX_WIDTH);
	if ((ray->side == 0 || ray->side == 2) && ray->dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if ((ray->side == 1 || ray->side == 3) && ray->dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

void	ft_draw_column(t_cub *cub, int x, t_player *player)
{
	t_ray		ray;
	t_column	column;
	double		orto_wall_dist;
	int			len;

	ft_calculate_ray_and_distances(x, &ray, player, cub);
	orto_wall_dist = ft_calculate_orto_wall_dist(&ray);
	ft_calculate_line_params(orto_wall_dist, &column.line_height, \
	&column.draw_start, &column.draw_end);
	column.tex_x = ft_calculate_tex_x(&ray, player, orto_wall_dist);
	len = column.draw_end - column.draw_start;
	column.buffer = (int *)malloc(sizeof(int) * len);
	if (!column.buffer)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": int *column.buffer", "\"\n"), 1);
	ft_fill_buffer(&column, &ray, cub);
	ft_shading(column.buffer, len, orto_wall_dist);
	ft_draw_vertical_line(x, &column, cub);
	free(column.buffer);
}
