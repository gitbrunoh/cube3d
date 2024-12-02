/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:43:29 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/02 18:46:14 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void ft_clear_cub(void)
{
    t_cub *cub;

    cub = ft_get_cub();
    // if (cub->fd != -1)
    //     close(cub->fd);
    // if (cub->line)
    //     free(cub->line);
    // if (cub->file)
    //     free(cub->file);
    // if (cub->map)
    //     ft_clear_map(cub->map);
    if (cub->img)
    {
        printf("Destroying image\n");
        mlx_destroy_image(cub->mlx_ptr, cub->img);
    }
    if (cub->win)
    {
        printf("Destroying window\n");
        mlx_destroy_window(cub->mlx_ptr, cub->win);
    }
    if (cub->mlx_ptr)
    {
        printf("Ending mlx loop\n");
        mlx_loop_end(cub->mlx_ptr);
        printf("Destroying display\n");
        mlx_destroy_display(cub->mlx_ptr);
        printf("Freeing mlx\n");
        free(cub->mlx_ptr);
    }
}
