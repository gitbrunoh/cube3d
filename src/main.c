/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/03 08:12:52 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static void	ft_clear_player(t_player *player)
{
	if (player)
		free(player);
}

static void	ft_clear_color(t_color *color)
{
	if (color->input)
		free(color->input);
	if (color)
		free(color);
}

static void	ft_clear_texture(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->east)
		free(texture->east);
	if (texture->west)
		free(texture->west);
	if (texture->ceiling)
		ft_clear_color(texture->ceiling);
	if (texture->floor)
		ft_clear_color(texture->floor);
	if (texture)
		free(texture);
}

static void	ft_clear_map(t_map *map)
{
	if (map && map->map)
		ft_free_array(map->map);
	if (map && map->ff_map)
		ft_free_array(map->ff_map);
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map->player)
		ft_clear_player(map->player);
	if (map)
		free(map);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_input_validation(av, ac);
	ft_input_parse(av, ac);
	cub = ft_init_cub();
    if (cub->fd != -1)
		close(cub->fd);
	if (cub->file)
		free(cub->file);
    if (cub->line)
        free(cub->line);
    if (cub->map)
		ft_clear_map(cub->map);
	ft_mlx_inicialization(cub);
	ft_mlx_getdata_and_loop(cub);
	return (0);
}