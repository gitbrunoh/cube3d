/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:02:39 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:14:25 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_open_door(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->map->player->p_x + cub->map->player->dir_vector->x);
	y = (int)(cub->map->player->p_y + cub->map->player->dir_vector->y);
	if (cub->map->map[x][y] == '2')
	{
		cub->map->map[x][y] = '3';
		ft_ray_casting(cub);
	}
}

void	ft_close_door(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->map->player->p_x);
	y = (int)(cub->map->player->p_y);
	if (cub->map->map[x][y] == '3')
	{
		return ;
	}
	x = (int)(cub->map->player->p_x + cub->map->player->dir_vector->x);
	y = (int)(cub->map->player->p_y + cub->map->player->dir_vector->y);
	if (cub->map->map[x][y] == '3')
	{
		cub->map->map[x][y] = '2';
		ft_ray_casting(cub);
	}
}
