/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:38:34 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/02 17:28:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

// static void	ft_print_texture(t_texture *texture)
// {
// 	printf("\nTEXTURES\n");
// 	printf("NO: %s\n", texture->north);
// 	printf("SO: %s\n", texture->south);
// 	printf("WE: %s\n", texture->west);
// 	printf("EA: %s\n", texture->east);
// 	printf("\nCOLORS\n");
// 	printf("C: %s\n", texture->ceiling->input);
// 	printf("F: %s\n", texture->floor->input);
// }

static void	ft_print_player(t_player *player)
{
	printf("\nPLAYER\n");
	printf("X: %d\n", player->p_x);
	printf("Y: %d\n", player->p_y);
	printf("DIR: %c\n", player->p_dir);
}

static void	ft_print_maps(char **map)
{
	unsigned int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

void	ft_print_map(t_map *map)
{
	//ft_print_texture(map->texture);
	printf("\nMAP\n");
	ft_print_maps(map->map);
	printf("\nFLOODED MAP\n");
	ft_print_maps(map->ff_map);
	ft_print_player(map->player);
}
