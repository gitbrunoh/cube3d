/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:10:52 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 13:42:16 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static bool	ft_player_dir(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'N' || map->map[x][y] == 'S' ||
		map->map[x][y] == 'E' || map->map[x][y] == 'W')
		return (true);
	return (false);
}

static void	ft_fill_player(t_map *map, int x, int y)
{
	if (map->player->p_dir != -1)
		ERROR_PRINT(ERROR_MSG(1, ERROR_PLAYER), 1);
	map->player->p_x = x;
	map->player->p_y = y;
	map->player->p_dir = map->map[x][y];
}

void	ft_check_player(t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
			if (ft_player_dir(map, x, y))
				ft_fill_player(map, x, y);
	}
	if (map->player->p_dir == -1)
		ERROR_PRINT(ERROR_MSG(1, ERROR_PLAYER), 1);
}

t_player	*ft_init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, ": t_player player", "\"\n"), 1);
	player->p_dir = -1;
	player->p_x = -1;
	player->p_y = -1;
	return (player);
}
