/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/01 18:41:29 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_call_hooks(t_cub *cub)
{
	mlx_hook(cub->win, 17, 1L << 7, ft_close_x, cub);
}

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLX), 1);
	cub->win = mlx_new_window(cub->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, NAME);
	if (!cub->win)
		ERROR_PRINT(ERROR_MSG(1, ERROR_WIN), 1);
	ft_image_hub(cub);
	ft_call_hooks(cub);
	mlx_loop(cub->mlx);
}
