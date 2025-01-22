/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:20:48 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:15:17 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	calculate_ray_direction(int x, t_ray *ray, t_player *player)
{
	double	param;

	param = (2 * x / (double)SCREEN_WIDTH) - 1;
	ray->dir_x = player->dir_vector->x + (param * player->cam_vector->x);
	ray->dir_y = player->dir_vector->y + (param * player->cam_vector->y);
}

void	calculate_delta_distances(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	calculate_initial_distances(t_player *player, t_ray *ray)
{
	ray->map_x = (int)player->p_x;
	ray->map_y = (int)player->p_y;
	calculate_delta_distances(ray);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->p_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->p_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->p_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->p_y) * ray->deltadist_y;
	}
}
