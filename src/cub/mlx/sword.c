/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:26 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 12:24:48 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

static void	ft_print_img_pixel( t_image *img, int x, int y, float scale)
{
	t_cub	*cub;
	int		tex_x;
	int		tex_y;

	cub = ft_get_cub();
	tex_x = x / scale;
	tex_y = y / scale;
	if (img->tex[tex_x][tex_y] != NONE)
		if (img->print_y + y >= 0 && img->print_y + y < SCREEN_HEIGHT)
			ft_my_mlx_pixel_put(cub, img->print_x + x, \
			img->print_y + y, img->tex[tex_x][tex_y]);
}

static void	ft_draw_image(t_image *img, int n_w, int n_h, float scale)
{
	int			y;
	int			x;

	y = -1;
	while (++y < n_h)
	{
		x = -1;
		while (++x < n_w)
			ft_print_img_pixel(img, x, y, scale);
	}
}

void	ft_draw_sword(t_image *sword, int w, int h, float scale)
{
	int			new_height;
	int			new_width;

	new_width = w * scale;
	new_height = h * scale;
	sword->print_x = SCREEN_WIDTH - (SCREEN_WIDTH / 1.7f);
	sword->print_y = SCREEN_HEIGHT - (new_height / 1.3f);
	ft_draw_image(sword, new_width, new_height, scale);
}
