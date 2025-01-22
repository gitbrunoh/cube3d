/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:54:18 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:22:45 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_prepare_vec(double angle, t_dir_vector *dir_vector, t_cub *cub)
{
	angle = ft_deg_to_rad(angle);
	dir_vector->x = cub->map->player->dir_vector->x;
	dir_vector->y = cub->map->player->dir_vector->y;
	ft_rotate_vect(angle, dir_vector);
	cub->map->player->ray->dir_x = dir_vector->x;
	cub->map->player->ray->dir_y = dir_vector->y;
}

static void	ft_collision_init(t_player *player)
{
	player->ray->map_x = (int)player->p_x;
	player->ray->map_y = (int)player->p_y;
	calculate_delta_distances(player->ray);
}

void	ft_collision_dists(t_player *player)
{
	ft_collision_init(player);
	if (player->ray->dir_x < 0)
	{
		player->ray->step_x = -1;
		player->ray->sidedist_x = (player->p_x - player->ray->map_x) \
		* player->ray->deltadist_x;
	}
	else
	{
		player->ray->step_x = 1;
		player->ray->sidedist_x = (player->ray->map_x + 1.0 - player->p_x) \
		* player->ray->deltadist_x;
	}
	if (player->ray->dir_y < 0)
	{
		player->ray->step_y = -1;
		player->ray->sidedist_y = (player->p_y - player->ray->map_y) \
		* player->ray->deltadist_y;
	}
	else
	{
		player->ray->step_y = 1;
		player->ray->sidedist_y = (player->ray->map_y + 1.0 - player->p_y) \
		* player->ray->deltadist_y;
	}
}

int	ft_collision_dda(t_player *player, t_cub *cub)
{
	while (true)
	{
		if (player->ray->sidedist_x < player->ray->sidedist_y)
		{
			player->ray->sidedist_x += player->ray->deltadist_x;
			player->ray->map_x += player->ray->step_x;
		}
		else
		{
			player->ray->sidedist_y += player->ray->deltadist_y;
			player->ray->map_y += player->ray->step_y;
		}
		if (cub->map->rows <= (unsigned int)player->ray->map_x || \
		cub->map->cols <= (unsigned int)player->ray->map_y)
			break ;
		if (cub->map->map[player->ray->map_x][player->ray->map_y] == '1' || \
		cub->map->map[player->ray->map_x][player->ray->map_y] == '2')
			break ;
	}
	return (0);
}

int	ft_collision(t_map *map, t_cub *cub)
{
	ft_collision_dists(map->player);
	ft_collision_dda(map->player, cub);
	if (map->player->ray->sidedist_x < 2.0 || \
	map->player->ray->sidedist_y < 2.0)
		return (1);
	return (0);
}
