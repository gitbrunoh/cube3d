/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/03 08:01:43 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	ft_mlx_inicialization(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
	{
		ft_clear_cub();
		perror("Error: mlx_init");
		exit (1);
	}
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
	{
		ft_clear_cub();
		perror("Error: mlx_new_window");
		exit (1);
	}
	cub->img = mlx_new_image(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img)
	{
		ft_clear_cub();
		perror("Error: mlx_new_image");
		exit (1);
	}
}

void	ft_mlx_getdata_and_loop(t_cub *cub)
{
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, \
	&cub->line_lenght, &cub->endian);
	if (!cub->addr)
	{	
		ft_clear_cub();
		perror("Error: mlx_get_data_addr");
		exit (1);
	}
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	//mlx_key_hook (cub->win, keys, cub); 
	//mlx_expose_hook(cub->win, draw, cub);
	mlx_loop (cub->mlx_ptr);
}

