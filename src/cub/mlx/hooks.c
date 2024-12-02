/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:11:30 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/02 20:17:52 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

int	ft_close_x(t_cub *cub)
{
	printf("cub->win: %p\n", cub->win);
	printf("cub->img: %p\n", cub->img);
	printf("cub->addr: %p\n", cub->addr);
	printf("cub->bpp: %d\n", cub->bpp);
	printf("cub->line_lenght: %d\n", cub->line_lenght);
	printf("cub->endian: %d\n", cub->endian);
	
	if (cub)
		ft_clear_cub();
	exit (0);
}
