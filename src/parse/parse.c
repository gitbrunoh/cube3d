/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:45:12 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/30 13:54:27 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_validate_arguments(int ac)
{
	if (ac == 2)
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_AC), 1);
}

static void	ft_validate_extension(char *name)
{
	int	len;

	len = ft_strlen(name);
	while (len > 0)
	{
		if (name[len] == '.')
		{
			if (ft_strcmp(&name[len], ".cub") == 0)
				return ;
			else
				ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
		}
		len--;
	}
	ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
}

static void	ft_parse_map(t_cub *cub, char *file)
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
		ft_parse_map(cub, input);
	close(cub->fd);
}

// confirm later if there is more to look for in the parse intput function

void	ft_parse_input(char **av, int ac)
{
	ft_validate_arguments(ac);
	ft_validate_extension(av[1]);
	ft_open_file(av[1]);
	ft_parse_texture(ft_get_cub());
}
