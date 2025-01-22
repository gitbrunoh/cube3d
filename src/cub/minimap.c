/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:34:59 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/05 11:33:31 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_draw_square(int x, int y, float scale, int color)
{
	t_cub	*cub;
	int		i;
	int		j;

	cub = ft_get_cub();
	i = 0;
	if (color == -1)
		return ;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			ft_my_mlx_pixel_put(cub, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_analyze_pos(t_cub *cub, int j, int i, float scale)
{
	int		x;
	int		y;

	x = j * scale;
	y = i * scale;
	if (cub->map->map[i][j] == '1')
		ft_draw_square(x, y, scale, 0x000000);
	else if (j == (int)cub->map->player->p_y \
	&& i == (int)cub->map->player->p_x)
		ft_draw_square(x, y, scale, 0xFF0000);
	else if (cub->map->map[i][j] == '0' || cub->map->map[i][j] == 'N'\
	|| cub->map->map[i][j] == 'S' || cub->map->map[i][j] == 'E'\
	|| cub->map->map[i][j] == 'W' || cub->map->map[i][j] == '3')
		ft_draw_square(x, y, scale, 0xFFFFFF);
	else if (cub->map->map[i][j] == '2')
		ft_draw_square(x, y, scale, 0x0000F0);
	else
		ft_draw_square(x, y, scale, -1);
}

void	ft_draw_minimap(t_cub *cub, t_player *player)
{
	int		i;
	int		j;
	float	scale;

	(void)player;
	scale = (SCREEN_WIDTH / 2) / (cub->map->cols + cub->map->rows);
	i = -1;
	while (++i < (int)cub->map->rows)
	{
		j = -1;
		while (++j < (int)cub->map->cols)
			ft_analyze_pos(cub, j, i, scale);
	}
}
