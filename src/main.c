/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/02 20:30:22 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	ft_mlx_inicialization(t_cub *cub)
{
	char *title;

	title = "cub3d brunhenr e ncampbel - 42Lisboa";
	cub->mlx_ptr = mlx_init();
	printf("cub->mlx: %p\n", cub->mlx_ptr);
	if (!cub->mlx_ptr)
	{
		//ft_clear_cub();
		perror("Error: mlx_init");
		exit (1);
	}
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, title);
	if (!cub->win)
	{
		//ft_clear_cub();
		perror("Error: mlx_new_window");
		exit (1);
	}
	cub->img = mlx_new_image(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img)
	{
		//ft_clear_cub();
		perror("Error: mlx_new_image");
		exit (1);
	}
}

void	ft_draw_lines_and_run_mlx(t_cub *cub)
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

static void	ft_clear_player(t_player *player)
{
	if (player)
		free(player);
}

static void	ft_clear_color(t_color *color)
{
	if (color->input)
		free(color->input);
	if (color)
		free(color);
}

static void	ft_clear_texture(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->east)
		free(texture->east);
	if (texture->west)
		free(texture->west);
	if (texture->ceiling)
		ft_clear_color(texture->ceiling);
	if (texture->floor)
		ft_clear_color(texture->floor);
	if (texture)
		free(texture);
}

static void	ft_clear_map(t_map *map)
{
	if (map && map->map)
		ft_free_array(map->map);
	if (map && map->ff_map)
		ft_free_array(map->ff_map);
	if (map->texture)
		ft_clear_texture(map->texture);
	if (map->path)
		free(map->path);
	if (map->player)
		ft_clear_player(map->player);
	if (map)
		free(map);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_input_validation(av, ac);
	ft_input_parse(av, ac);

	//cub = ft_get_cub();
	cub = ft_init_cub();
    // if (cub->fd != -1)
    //     close(cub->fd);
	if (cub->file)
		free(cub->file);
    if (cub->line)
        free(cub->line);
    if (cub->map)
		ft_clear_map(cub->map);

	ft_mlx_inicialization(cub);

	ft_draw_lines_and_run_mlx(cub);
	
	printf("cub->win: %p\n", cub->win);
	printf("cub->img: %p\n", cub->img);
	printf("cub->addr: %p\n", cub->addr);
	printf("cub->bpp: %d\n", cub->bpp);
	printf("cub->line_lenght: %d\n", cub->line_lenght);
	printf("cub->endian: %d\n", cub->endian);

	ft_clear_cub();
	return (0);
}
