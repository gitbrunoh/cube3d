/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/10 16:43:53 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_is_there_doortex(t_cub *cub)
{
	if (cub->map->texture->door->path == NULL)
	{
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_DOOR, 0), 1);
		ft_clear_cub();
		exit(1);
	}
}

void	ft_look_for_invalid_map(t_cub *cub)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < cub->map->rows)
	{
		j = -1;
		while (++j < ft_strlen(cub->map->map[i]))
		{
			if (cub->map->map[i][j] == '2')
				ft_is_there_doortex(cub);
			if (cub->map->map[i][j] != '1' && cub->map->map[i][j] != '0' \
			&& cub->map->map[i][j] != '2' && cub->map->map[i][j] != ' ' \
			&& cub->map->map[i][j] != 'N' && cub->map->map[i][j] != 'S' \
			&& cub->map->map[i][j] != 'E' && cub->map->map[i][j] != 'W' \
			&& cub->map->map[i][j] != '\n' && cub->map->map[i][j] != '\0')
				ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CHAR, 0), 1);
		}
	}
}

void	ft_get_map_textures(t_map *map, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	ft_get_text_color(map, split);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

void	ft_trim_map(t_cub *cub)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < cub->map->rows)
	{
		j = -1;
		while (cub->map->map[i][++j])
			if (cub->map->map[i][j] == '\n')
				cub->map->map[i][j] = '\0';
	}
}
