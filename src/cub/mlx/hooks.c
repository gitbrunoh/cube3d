/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/04 21:17:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_hub(t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	if (cub->keys.left)
	{
		ft_rotate_left(cub->map->player, cub);
		if (!ft_perpendicular_vect(player->dir_vector, player->cam_vector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	if (cub->keys.right)
	{
		ft_rotate_right(cub->map->player, cub);
		if (!ft_perpendicular_vect(player->dir_vector, player->cam_vector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
}

void	ft_move_hub(t_cub *cub)
{
	if (cub->keys.w)
	{
		if (cub->keys.shift)
			cub->frame_time.move_speed = cub->frame_time.move_speed * 2;
		ft_move_forward(cub);
	}
	else if (cub->keys.s)
		ft_move_backward(cub);
	else if (cub->keys.a)
		ft_move_left(cub);
	else if (cub->keys.d)
		ft_move_right(cub);
}

int	ft_close_x(t_cub *cub)
{
	if (cub)
		ft_clear_cub();
	exit (0);
}

int	ft_keys(t_cub *cub)
{
	if (cub->keys.esc)
		ft_close_x(cub);
	if (cub->keys.left || cub->keys.right)
		ft_rotate_hub(cub);
	if (cub->keys.w || cub->keys.s
		|| cub->keys.a || cub->keys.d)
		ft_move_hub(cub);
	if (cub->keys.e)
		ft_open_door(cub);
	else if (cub->keys.c)
		ft_close_door(cub);
	return (0);
}
