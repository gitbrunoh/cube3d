/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:51:17 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/21 17:49:21 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	ft_map_move(t_cub *cub)
{
	t_player	*player;
	t_map		*map;
	int			x;
	int			y;

	map = cub->map;
	player = map->player;
	x = -1;
	while (++x < (int)map->rows)
	{
		y = -1;
		while (++y < (int)map->cols)
			if (map->map[x][y] == player->p_dir)
				map->map[x][y] = '0';
	}
	map->map[(int)player->p_x][(int)player->p_y] = player->p_dir;
}
