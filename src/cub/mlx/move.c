/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:47:40 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/04 21:22:26 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_move_forward(t_cub *cub)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	cub->map->player->ray->dir_x = cub->map->player->dir_vector->x;
	cub->map->player->ray->dir_y = cub->map->player->dir_vector->y;
	map = cub->map;
	if (ft_collision(map, cub))
		return ;
	new_x = (int)(map->player->p_x + (map->player->dir_vector->x \
	* cub->frame_time.move_speed));
	new_y = (int)(map->player->p_y + (map->player->dir_vector->y \
	* cub->frame_time.move_speed));
	if (new_x < 0 || new_x >= (int)map->rows || \
	new_y < 0 || new_y >= (int)map->cols)
		return ;
	if (ft_is_walkable(map->map[new_x][new_y]))
	{
		map->player->p_x += map->player->dir_vector->x \
		* cub->frame_time.move_speed;
		map->player->p_y += map->player->dir_vector->y \
		* cub->frame_time.move_speed;
		ft_ray_casting(cub);
	}
}

void	ft_move_backward(t_cub *cub)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	cub->map->player->ray->dir_x = cub->map->player->dir_vector->x * -1;
	cub->map->player->ray->dir_y = cub->map->player->dir_vector->y * -1;
	map = cub->map;
	if (ft_collision(map, cub))
		return ;
	new_x = (int)(map->player->p_x - (map->player->dir_vector->x \
	* cub->frame_time.move_speed));
	new_y = (int)(map->player->p_y - (map->player->dir_vector->y \
	* cub->frame_time.move_speed));
	if (new_x < 0 || new_x >= (int)map->rows || \
	new_y < 0 || new_y >= (int)map->cols)
		return ;
	if (ft_is_walkable(map->map[new_x][new_y]))
	{
		map->player->p_x -= map->player->dir_vector->x \
		* cub->frame_time.move_speed;
		map->player->p_y -= map->player->dir_vector->y \
		* cub->frame_time.move_speed;
		ft_ray_casting(cub);
	}
}

void	ft_move_right(t_cub *cub)
{
	t_map			*map;
	int				new_x;
	int				new_y;
	t_dir_vector	dir_vector;

	ft_prepare_vec(-90, &dir_vector, cub);
	map = cub->map;
	if (ft_collision(map, cub))
		return ;
	new_x = (int)(map->player->p_x + (map->player->dir_vector->y \
	* cub->frame_time.move_speed));
	new_y = (int)(map->player->p_y - (map->player->dir_vector->x \
	* cub->frame_time.move_speed));
	if (new_x < 0 || new_x >= (int)map->rows || \
	new_y < 0 || new_y >= (int)map->cols)
		return ;
	if (ft_is_walkable(map->map[new_x][new_y]))
	{
		map->player->p_x += map->player->dir_vector->y \
		* cub->frame_time.move_speed;
		map->player->p_y -= map->player->dir_vector->x \
		* cub->frame_time.move_speed;
		ft_ray_casting(cub);
	}
}

void	ft_move_left(t_cub *cub)
{
	t_map			*map;
	int				new_x;
	int				new_y;
	t_dir_vector	dir_vector;

	ft_prepare_vec(90, &dir_vector, cub);
	map = cub->map;
	if (ft_collision(map, cub))
		return ;
	new_x = (int)(map->player->p_x - (map->player->dir_vector->y \
	* cub->frame_time.move_speed));
	new_y = (int)(map->player->p_y + (map->player->dir_vector->x \
	* cub->frame_time.move_speed));
	if (new_x < 0 || new_x >= (int)map->rows || \
	new_y < 0 || new_y >= (int)map->cols)
		return ;
	if (ft_is_walkable(map->map[new_x][new_y]))
	{
		map->player->p_x -= map->player->dir_vector->y \
		* cub->frame_time.move_speed;
		map->player->p_y += map->player->dir_vector->x \
		* cub->frame_time.move_speed;
		ft_ray_casting(cub);
	}
}
