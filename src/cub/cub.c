/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/23 17:38:06 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_cub	*ft_get_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

static void	ft_init_keys(t_cub *cub)
{
	cub->keys.w = false;
	cub->keys.a = false;
	cub->keys.s = false;
	cub->keys.d = false;
	cub->keys.left = false;
	cub->keys.right = false;
	cub->keys.esc = false;
	cub->keys.e = false;
	cub->keys.c = false;
}

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_get_cub();
	ft_alloc_map(cub);
	ft_look_for_invalid_map(cub);
	ft_trim_map(cub);
	ft_call_flood(cub->map);
	ft_check_player(cub->map);
	ft_normalize_map(cub);
	ft_init_keys(cub);
	return (cub);
}
