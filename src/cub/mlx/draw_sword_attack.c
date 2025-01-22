/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sword_attack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:21:16 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 20:27:34 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static int	get_frame_y(t_player *player)
{
	return (player->attack->frame_w * player->attack->cur_frame);
}

static float	calculate_scale(int screen_height, int frame_height)
{
	return ((float)screen_height / frame_height);
}

static void	calculate_dimensions(t_player *player)
{
	t_sprite	*attack;

	attack = player->attack;
	attack->new_w = player->attack->frame_w * attack->sprt_scl;
	attack->new_h = player->attack->frame_h * attack->sprt_scl;
}

static void	calculate_start_positions(int screen_width, int screen_height)
{
	t_sprite	*attack;

	attack = ft_get_cub()->map->player->attack;
	attack->start_x = screen_width - (screen_width / 1.7f);
	attack->start_y = screen_height - (attack->new_h / 1.3f);
}

void	draw_sword_attack(t_cub *cub, t_player *player)
{
	t_sprite	*attack;

	attack = player->attack;
	attack->frame_y = get_frame_y(player);
	if (attack->frame_y == player->attack->sprite_sheet->width)
		return ;
	attack->sprt_scl = calculate_scale(SCREEN_HEIGHT, player->attack->frame_h);
	calculate_dimensions(player);
	calculate_start_positions(SCREEN_WIDTH, SCREEN_HEIGHT);
	draw_frame(cub, player);
}
