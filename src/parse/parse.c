/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:31 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/02 20:06:58 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_clean_map_spaces(char **line)
{
	int	j;

	j = -1;
	while ((*line)[++j])
	{
		if (ft_isspace((*line)[j]) && (*line)[j] != ' ')
			(*line)[j] = ' ';
	}
}

static void	ft_get_map_info(t_cub *cub, char *line)
{
	ft_clean_map_spaces(&line);
	ft_get_map_textures(cub->map, line);
}

static void	ft_parse_input(t_cub *cub, char *file)
{
	cub->file = ft_strdup(file);
	ft_init_map(cub);
	while (cub->line)
	{
		if (!ft_is_text_or_color(cub->line))
			cub->map->rows++;
		if (ft_strlen(cub->line) > INT_MAX)
			ERROR_PRINT(ERROR_MSG(3, ERROR_MAP_SIZE, file, "\"\n"), 1);
		ft_get_map_info(cub, cub->line);
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	if (cub->map->rows == 0 || cub->map->rows > INT_MAX)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MAP_SIZE, file, "\"\n"), 1);
}

static void	ft_open_file(char *input)
{
	t_cub	*cub;

	cub = ft_get_cub();
	cub->fd = open(input, O_RDONLY);
	if (cub->fd == -1)
		ERROR_PRINT(ERROR_MSG(3, ERROR_OPEN, input, "\"\n"), 1);
	cub->line = get_next_line(cub->fd);
	if (cub->line == NULL)
		ERROR_PRINT(ERROR_MSG(3, ERROR_READ, input, "\"\n"), 1);
	else
		ft_parse_input(cub, input);
	close(cub->fd);
	free(cub->line); //esse free vai ficar aqui? vejamos se da na mesma
}

void	ft_input_parse(char **av, int ac)
{
	if (ac != 2)
		ERROR_PRINT(ERROR_MSG(1, ERROR_AC), 1);
	ft_open_file(av[1]);
	ft_parse_texture(ft_get_cub());
}