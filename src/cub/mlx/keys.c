/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:29:57 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:17:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_rotate_left(t_player *player, t_cub *cub)
{
	double	angle;

	angle = cub->frame_time.rot_speed;
	ft_rotate_vect(angle, player->dir_vector);
	ft_rotate_vect(angle, player->cam_vector);
}

void	ft_rotate_right(t_player *player, t_cub *cub)
{
	double	angle;

	angle = cub->frame_time.rot_speed * -1;
	ft_rotate_vect(angle, player->dir_vector);
	ft_rotate_vect(angle, player->cam_vector);
}

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->keys.w = true;
	else if (keycode == KEY_S)
		cub->keys.s = true;
	else if (keycode == KEY_A)
		cub->keys.a = true;
	else if (keycode == KEY_D)
		cub->keys.d = true;
	else if (keycode == KEY_LEFT)
		cub->keys.left = true;
	else if (keycode == KEY_RIGHT)
		cub->keys.right = true;
	else if (keycode == KEY_ESC)
		cub->keys.esc = true;
	else if (keycode == KEY_E)
		cub->keys.e = true;
	else if (keycode == KEY_C)
		cub->keys.c = true;
	else if (keycode == KEY_SHIFT)
		cub->keys.shift = true;
	return (0);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->keys.w = false;
	else if (keycode == KEY_S)
		cub->keys.s = false;
	else if (keycode == KEY_A)
		cub->keys.a = false;
	else if (keycode == KEY_D)
		cub->keys.d = false;
	else if (keycode == KEY_LEFT)
		cub->keys.left = false;
	else if (keycode == KEY_RIGHT)
		cub->keys.right = false;
	else if (keycode == KEY_ESC)
		cub->keys.esc = false;
	else if (keycode == KEY_E)
		cub->keys.e = false;
	else if (keycode == KEY_C)
		cub->keys.c = false;
	else if (keycode == KEY_SHIFT)
		cub->keys.shift = false;
	return (0);
}
