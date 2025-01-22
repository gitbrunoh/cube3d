/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:00:34 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/13 12:52:55 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_check_dup_color(t_color *color, char *line, char **split)
{
	if (color->input)
	{
		ft_free_array(split);
		ERROR_PRINT(ERROR_MSG(1, ERROR_MAP_DUPLICATE), 1);
	}
	color->input = ft_strdup(line);
}

void	ft_check_errors(t_cub *cub, char **split)
{
	if (strcmp(split[0], "F") == 0)
	{
		if (cub->map->texture->floor->red == -1
			|| cub->map->texture->floor->green == -1
			|| cub->map->texture->floor->blue == -1)
		{
			ft_free_array(split);
			ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
		}
	}
	else if (strcmp(split[0], "C") == 0)
	{
		if (cub->map->texture->ceiling->red == -1
			|| cub->map->texture->ceiling->green == -1
			|| cub->map->texture->ceiling->blue == -1)
		{
			ft_free_array(split);
			ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
		}
	}
}

void	ft_create_colors(t_cub *cub, char *line)
{
	t_color	*color;

	if (strncmp(line, "F", 1) == 0)
		color = cub->map->texture->floor;
	else
		color = cub->map->texture->ceiling;
	color->color = ft_create_rgb(color->red, color->green, color->blue);
}
