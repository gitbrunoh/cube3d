/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:14:34 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 20:19:43 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_set_w_h_and_tex(int w, int h, t_image *image)
{
	image->width = w;
	image->height = h;
	image->tex = ft_get_image_pixels(image->img, image->width, image->height);
}

void	ft_get_tex_imgs(t_cub *cub, t_texture *texture)
{
	int	width;
	int	height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	texture->north->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->north->path, &width, &height);
	texture->south->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->south->path, &width, &height);
	texture->west->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->west->path, &width, &height);
	texture->east->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
	texture->east->path, &width, &height);
	if (texture->door->path)
	{
		texture->door->img = mlx_xpm_file_to_image(cub->mlx_ptr, \
		texture->door->path, &width, &height);
		ft_set_w_h_and_tex(TEX_WIDTH, TEX_HEIGHT, texture->door);
	}
	ft_set_w_h_and_tex(TEX_WIDTH, TEX_HEIGHT, texture->north);
	ft_set_w_h_and_tex(TEX_WIDTH, TEX_HEIGHT, texture->south);
	ft_set_w_h_and_tex(TEX_WIDTH, TEX_HEIGHT, texture->west);
	ft_set_w_h_and_tex(TEX_WIDTH, TEX_HEIGHT, texture->east);
}
