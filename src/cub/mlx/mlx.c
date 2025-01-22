/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/08 10:01:55 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_get_player_images(t_cub *cub, t_player *player)
{
	t_image		*sprite;

	sprite = load_sprite_sheet(cub->mlx_ptr, \
	"./includes/textures/sprites/attack/attackss2.xpm", \
	SPRITE_WIDTH, SPRITE_HEIGHT);
	if (sprite)
		player->attack = init_sprite(sprite, 64, 64, SPRITE_LEN);
	player->sword = load_sprite_sheet(cub->mlx_ptr, \
	"./includes/textures/anduril_rest.xpm", SWORD_WIDTH, SWORD_HEIGHT);
}

void	ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = cub->addr + (y * cub->line_length + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLX), 1);
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
		ERROR_PRINT(ERROR_MSG(1, ERROR_WIN), 1);
	ft_get_tex_imgs(cub, cub->map->texture);
	ft_get_player_images(cub, cub->map->player);
	ft_image_hub(cub);
}

void	ft_mlx_hook_and_loop(t_cub *cub)
{
	cub->mouse_x = SCREEN_WIDTH / 2;
	mlx_hook(cub->win, 6, POINTERMOTION_MASK, ft_mouse, cub);
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	mlx_hook(cub->win, 2, KEYPRESS_MASK, ft_key_press, cub);
	mlx_hook(cub->win, 3, KEYRELEASE_MASK, ft_key_release, cub);
	mlx_hook (cub->win, 4, BUTTONPRESS_MASK, ft_mouse_click, cub);
	mlx_expose_hook(cub->win, ft_ray_casting, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_keys, cub);
	mlx_loop (cub->mlx_ptr);
}
