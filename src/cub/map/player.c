/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:10:52 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/04 21:15:17 by brunhenr         ###   ########.fr       */
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

static void	initial_player_dir(t_map *map)
{
	if (map->player->p_dir == 78)
	{
		map->player->dir_vector->x = -0.66;
		map->player->dir_vector->y = 0;
	}
	else if (map->player->p_dir == 83)
	{
		map->player->dir_vector->x = 0.66;
		map->player->dir_vector->y = 0;
	}
	else if (map->player->p_dir == 69)
	{
		map->player->dir_vector->x = 0;
		map->player->dir_vector->y = 0.66;
	}
	else if (map->player->p_dir == 87)
	{
		map->player->dir_vector->x = 0;
		map->player->dir_vector->y = -0.66;
	}
}

static void	initial_cam_dir(t_map *map)
{
	if (map->player->p_dir == 78)
	{
		map->player->cam_vector->x = 0;
		map->player->cam_vector->y = 0.66;
	}
	else if (map->player->p_dir == 83)
	{
		map->player->cam_vector->x = 0;
		map->player->cam_vector->y = -0.66;
	}
	else if (map->player->p_dir == 69)
	{
		map->player->cam_vector->x = 0.66;
		map->player->cam_vector->y = 0;
	}
	else if (map->player->p_dir == 87)
	{
		map->player->cam_vector->x = -0.66;
		map->player->cam_vector->y = 0;
	}
}

static void	ft_fill_player(t_map *map, int x, int y)
{
	if (map->player->p_dir != -1)
		ERROR_PRINT(ERROR_MSG(1, ERROR_PLAYER), 1);
	map->player->p_x = x + 0.5;
	map->player->p_y = y + 0.5;
	map->player->p_dir = map->map[x][y];
	map->player->is_attacking = false;
	initial_player_dir(map);
	initial_cam_dir(map);
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
