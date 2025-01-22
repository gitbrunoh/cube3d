/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:39:18 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 13:28:19 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static bool	ft_protect_color(char **arr, char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	if (ft_array_len(rgb) != 3 || ft_amount_char(color, ',') != 2)
	{
		ft_free_array(arr);
		ft_free_array(rgb);
		ERROR_PRINT(ERROR_MSG(1, ERROR_NULL_TEXT), 1);
	}
	else if (!ft_isdigit_str(rgb[0]) || !ft_isdigit_str(rgb[1]) \
	|| !ft_isdigit_str(rgb[2]))
	{
		ft_free_array(arr);
		ft_free_array(rgb);
		ERROR_PRINT(ERROR_MSG(1, ERROR_COL_NUM), 1);
	}
	ft_free_array(rgb);
	return (true);
}

static void	ft_prepare_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] == '\n')
			line[i] = '\0';
}

static void	ft_set_color(t_color *color, char *col_inpt, char **split)
{
	char	**rgb;

	rgb = ft_split(col_inpt, ',');
	if ((ft_atol(rgb[0]) < 0 || ft_atol(rgb[0]) > 255) \
	|| (ft_atol(rgb[1]) < 0 || ft_atol(rgb[1]) > 255) \
	|| (ft_atol(rgb[2]) < 0 || ft_atol(rgb[2]) > 255))
	{
		ft_free_array(rgb);
		ft_free_array(split);
		ERROR_PRINT(ERROR_MSG(1, ERROR_COL_RANGE), 1);
	}
	color->red = ft_atoi(rgb[0]);
	color->green = ft_atoi(rgb[1]);
	color->blue = ft_atoi(rgb[2]);
	ft_free_array(rgb);
}

static void	ft_get_color(t_cub *cub, char *line)
{
	t_texture	*texture;
	char		**split;

	split = ft_split(line, ' ');
	texture = cub->map->texture;
	if (!split)
		ERROR_PRINT(ERROR_MSG(1, ERROR_SPLIT), 1);
	if (ft_strcmp(split[0], "F") == 0 && ft_protect_color(split, split[1]))
	{
		ft_check_dup_color(texture->floor, line, split);
		ft_set_color(texture->floor, split[1], split);
	}
	else if (ft_strcmp(split[0], "C") == 0 && ft_protect_color(split, split[1]))
	{
		ft_check_dup_color(texture->ceiling, line, split);
		ft_set_color(texture->ceiling, split[1], split);
	}
	ft_free_array(split);
}

void	ft_parse_color(t_cub *cub, char	*line)
{
	ft_prepare_line(line);
	ft_get_color(cub, line);
	ft_create_colors(cub, line);
}
