/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:48:33 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/07 18:01:49 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_clear_images(t_cub *cub)
{
	if (cub->img)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img);
		if (cub->map->texture->north->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->north->img);
		if (cub->map->texture->south->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->south->img);
		if (cub->map->texture->west->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->west->img);
		if (cub->map->texture->east->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->east->img);
		if (cub->map->texture->door->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->texture->door->img);
		if (cub->map->player->attack && \
		cub->map->player->attack->sprite_sheet->img)
			mlx_destroy_image(cub->mlx_ptr, \
			cub->map->player->attack->sprite_sheet->img);
		if (cub->map->player->sword && cub->map->player->sword->img)
			mlx_destroy_image(cub->mlx_ptr, cub->map->player->sword->img);
	}
}

static void	ft_clear_window(t_cub *cub)
{
	if (cub->win)
		mlx_destroy_window(cub->mlx_ptr, cub->win);
}

static void	ft_clear_mlx(t_cub *cub)
{
	if (cub->mlx_ptr)
	{
		mlx_loop_end(cub->mlx_ptr);
		mlx_destroy_display(cub->mlx_ptr);
		free(cub->mlx_ptr);
	}
}

static void	ft_clear_file_descriptors(t_cub *cub)
{
	if (cub->fd != -1)
		close(cub->fd);
	if (cub->line)
		free(cub->line);
	if (cub->file)
		free(cub->file);
}

void	ft_clear_cub(void)
{
	t_cub	*cub;

	cub = ft_get_cub();
	ft_clear_images(cub);
	ft_clear_window(cub);
	ft_clear_mlx(cub);
	ft_clear_file_descriptors(cub);
	if (cub->map)
		ft_clear_map(cub->map);
}
