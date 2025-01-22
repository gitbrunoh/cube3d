/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:55:19 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:12:40 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	update_side_dist(t_ray *ray)
{
	if (ray->sidedist_x < ray->sidedist_y)
	{
		ray->sidedist_x += ray->deltadist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 2;
	}
	else
	{
		ray->sidedist_y += ray->deltadist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->side = 3;
		else
			ray->side = 1;
	}
}

static void	check_hit(t_cub *cub, t_ray *ray)
{
	if (cub->map->rows <= (unsigned int)ray->map_x || \
	cub->map->cols <= (unsigned int)ray->map_y)
	{
		ray->hit = 1;
		return ;
	}
	if (cub->map->map[ray->map_x][ray->map_y] == '1')
		ray->hit = 1;
	else if (cub->map->map[ray->map_x][ray->map_y] == '2')
		ray->hit = 2;
}

void	ft_perform_dda(t_cub *cub, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		update_side_dist(ray);
		check_hit(cub, ray);
	}
}
