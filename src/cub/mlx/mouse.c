/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:41:56 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/07 17:24:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

int	ft_mouse_click(int button, int x, int y, t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (!player->is_attacking && player->attack)
		{
			player->is_attacking = true;
			player->attack->cur_frame = 0;
			while (player->attack->cur_frame <= player->attack->num_frames -1)
			{
				update_animation(player->attack);
				ft_ray_casting(cub);
			}
		}
	}
	player->is_attacking = false;
	ft_ray_casting(cub);
	return (0);
}

int	ft_mouse(int x, int y, t_cub *cub)
{
	t_player	*player;

	player = cub->map->player;
	(void)y;
	if (cub->mouse_x < x)
	{
		ft_rotate_right(player, cub);
		if (!ft_perpendicular_vect(player->dir_vector, player->cam_vector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	else if (cub->mouse_x > x)
	{
		ft_rotate_left(player, cub);
		if (!ft_perpendicular_vect(player->dir_vector, player->cam_vector))
			ERROR_PRINT(ERROR_MSG(1, ERROR_VECTORS), 1);
		ft_ray_casting(cub);
	}
	cub->mouse_x = x;
	return (0);
}
