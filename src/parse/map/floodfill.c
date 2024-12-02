/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:46:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 13:50:29 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_analyze_cell(t_map *map, int col, int row)
{
	if ((col >= 0 || col < (int)ft_strlen(map->ff_map[row]) \
		|| row >= 0 || row < (int)map->rows) && (map->ff_map[row][col] == ' ' \
		|| map->ff_map[row][col] == 0))
		return ;
}

static void	ft_floodfill(t_map *map, int col, int row)
{
	if (col < 0 || col >= (int)ft_strlen(map->ff_map[row])
		|| row < 0 || row >= (int)map->rows || map->ff_map[row][col] == ' '
		|| map->ff_map[row][col] == '1' || map->ff_map[row][col] == 'x'
		|| map->ff_map[row][col] == 0)
	{
		ft_analyze_cell(map, col, row);
		return ;
	}
	map->ff_map[row][col] = 'x';
	ft_floodfill(map, col + 1, row);
	ft_floodfill(map, col - 1, row);
	ft_floodfill(map, col, row + 1);
	ft_floodfill(map, col, row - 1);
}

void	ft_call_flood(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	map->ff_map = ft_strdupd(map->map);
	while (map->ff_map[++i])
	{
		j = -1;
		while (map->ff_map[i][++j])
			if (map->ff_map[i][j] == '0')
				ft_floodfill(map, j, i);
	}
}
