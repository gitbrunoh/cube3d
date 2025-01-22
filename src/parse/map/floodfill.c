/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:46:29 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/12 19:10:42 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_analyze_cell(t_map *map, int col, int row)
{
	if (row < 0 || row >= (int)map->rows || col < 0
		|| col >= (int)ft_strlen(map->ff_map[row]))
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
	if (map->ff_map[row][col] == ' ' || map->ff_map[row][col] == 0)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CLOSE), 1);
}

static void	ft_floodfill(t_map *map, int col, int row)
{
	if (row < 0 || row >= (int)map->rows
		|| col < 0 || col >= (int)ft_strlen(map->ff_map[row])
		|| map->ff_map[row][col] == ' ' \
		|| map->ff_map[row][col] == '1' \
		|| map->ff_map[row][col] == 'x' \
		|| map->ff_map[row][col] == '\0')
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
			if (map->ff_map[i][j] == '0' || map->ff_map[i][j] == 'N' \
				|| map->ff_map[i][j] == 'S' || map->ff_map[i][j] == 'E' \
				|| map->ff_map[i][j] == 'W' || map->ff_map[i][j] == '2')
				ft_floodfill(map, j, i);
	}
}
