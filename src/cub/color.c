/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:06 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 13:14:35 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_color	*ft_init_color(void)
{
	t_color	*color;

	color = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!color)
		ERROR_PRINT(ERROR_MSG(3, ERROR_MLC, ": t_color color", "\"\n"), 1);
	color->color = -1;
	color->red = -1;
	color->green = -1;
	color->blue = -1;
	return (color);
}

int	ft_create_rgb(int r, int g, int b)
{
	int	new_color;

	new_color = (r << 16 | g << 8 | b);
	return (new_color);
}
