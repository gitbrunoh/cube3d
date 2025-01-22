/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:12:33 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/02 14:52:38 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static int	ft_apply_shading(int color, double shading_factor)
{
	int		r;
	int		g;
	int		b;

	r = ((color >> 16) & 0xFF) * shading_factor;
	g = ((color >> 8) & 0xFF) * shading_factor;
	b = (color & 0xFF) * shading_factor;
	return ((r << 16) | (g << 8) | b);
}

void	ft_shading(int *buffer, int len, double orto_wall_dist)
{
	int		i;
	double	shading_factor;

	i = 0;
	shading_factor = 1.0 / (1.0 + orto_wall_dist * \
	orto_wall_dist * SHADE_FACTOR);
	while (i < len)
	{
		buffer[i] = ft_apply_shading(buffer[i], shading_factor);
		i++;
	}
}
