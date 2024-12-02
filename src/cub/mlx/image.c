/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:14:37 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/01 18:53:11 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_image_hub(t_cub *cub)
{
	cub->img_ptr = MLX_NI(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img_ptr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_IMG), 1);
	cub->addr = MLX_GTA(cub->img_ptr, &cub->bpp, &cub->line_len, &cub->endian);
	MLX_PITW(cub->mlx, cub->win, cub->img_ptr, 0, 0);
}
