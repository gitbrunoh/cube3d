/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:14:37 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/11 00:15:39 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_image_hub(t_cub *cub)
{
	if (cub->img)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	cub->img = MLX_NI(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img)
		ERROR_PRINT(ERROR_MSG(1, ERROR_IMG), 1);
	cub->addr = MLX_GDA(cub->img, &cub->bpp, &cub->line_length, &cub->endian);
	if (!cub->addr)
		ERROR_PRINT(ERROR_MSG(1, ERROR_GDA), 1);
}
