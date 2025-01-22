/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:10:15 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 20:17:48 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_check_for_null(t_texture *texture)
{
	if (!texture->north->path || !texture->south->path || \
	!texture->west->path || !texture->east->path \
	|| !texture->ceiling || !texture->floor)
		ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
}

static void	ft_validate_and_open(t_cub *cub, char *path)
{
	ft_validate_extension(path, ".xpm");
	cub->fd = open(path, O_RDONLY);
	if (cub->fd < 0)
		ERROR_PRINT(ERROR_MSG(3, ERROR_TEXT, path, "\"\n", 0), 1);
	close(cub->fd);
}

static void	ft_check_files(t_cub *cub, t_texture *texture)
{
	ft_validate_and_open(cub, texture->north->path);
	ft_validate_and_open(cub, texture->south->path);
	ft_validate_and_open(cub, texture->west->path);
	ft_validate_and_open(cub, texture->east->path);
	if (texture->door->path)
		ft_validate_and_open(cub, texture->door->path);
}

void	ft_parse_texture(void)
{
	t_texture	*texture;
	t_cub		*cub;

	cub = ft_get_cub();
	texture = cub->map->texture;
	ft_check_for_null(texture);
	ft_check_files(cub, texture);
}
