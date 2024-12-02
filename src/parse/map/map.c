/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:54 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 13:43:35 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_check_for_null(t_texture *texture)
{
	if (!texture->north || !texture->south || !texture->west || !texture->east \
	|| !texture->ceiling || !texture->floor)
		ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
}

void	ft_parse_texture(t_cub *cub)
{
	t_texture	*texture;

	texture = cub->map->texture;
	cub->fd = open(cub->map->texture->north, O_RDONLY);
	ft_check_for_null(texture);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, texture->north, "\"\n", 0), 1);
	close(cub->fd);
	cub->fd = open(texture->south, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, texture->south, "\"\n", 0), 1);
	close(cub->fd);
	cub->fd = open(texture->west, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, texture->west, "\"\n", 0), 1);
	close(cub->fd);
	cub->fd = open(texture->east, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, texture->east, "\"\n", 0), 1);
	close(cub->fd);
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
			if (cub->map->map[i][j] == '\t')
				ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_CHAR, 0), 1);
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
				cub->map->map[i][j] = 0;
	}
}
