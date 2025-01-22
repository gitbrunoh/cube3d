/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:43:51 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/05 21:03:19 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

// this function will normalize the map n_col

static void	ft_grow_line(t_cub *cub, int i, int n_col)
{
	char	*new_line;
	int		j;

	new_line = ft_calloc(n_col + 1, sizeof(char));
	if (!new_line)
		ERROR_PRINT(ERROR_MSG(1, ERROR_MLC), 1);
	j = -1;
	while (cub->map->map[i][++j])
		new_line[j] = cub->map->map[i][j];
	while (j < n_col)
		new_line[j++] = ' ';
	free(cub->map->map[i]);
	cub->map->map[i] = new_line;
}

void	ft_normalize_map(t_cub *cub)
{
	unsigned int	i;

	i = -1;
	cub->map->cols = 0;
	while (++i < cub->map->rows)
		if (cub->map->cols < ft_strlen(cub->map->map[i]))
			cub->map->cols = ft_strlen(cub->map->map[i]);
	i = -1;
	while (++i < cub->map->rows)
		if (ft_strlen(cub->map->map[i]) < cub->map->cols)
			ft_grow_line(cub, i, cub->map->cols);
}
