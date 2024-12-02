/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:06 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/28 16:19:17 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_color	*ft_init_color(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->input = NULL;
	color->color = -1;
	color->red = -1;
	color->green = -1;
	color->blue = -1;
	return (color);
}

int	ft_create_rgb(int r, int g, int b)
{
	int	new_color;

	r = r % 256;
	g = g % 256;
	b = b % 256;
	new_color = (r << 16 | g << 8 | b);
	return (new_color);
}
