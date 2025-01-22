/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:08:00 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/05 17:08:03 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_validate_arguments(int ac)
{
	if (ac == 2)
		return ;
	else
		ERROR_PRINT(ERROR_MSG(1, ERROR_AC), 1);
}

void	ft_validate_extension(char *name, char *ext)
{
	int	len;

	len = ft_strlen(name);
	while (len > 0)
	{
		if (name[len] == '.')
		{
			if (ft_strcmp(&name[len], ext) == 0)
				return ;
			else
				ERROR_PRINT(ERROR_MSG(3, ERROR_EXT, name, "\"\n"), 1);
		}
		len--;
	}
	ERROR_PRINT(ERROR_MSG(3, ERROR_EXT, name, "\"\n"), 1);
}

void	ft_input_validation(char **av, int ac)
{
	ft_validate_arguments(ac);
	ft_validate_extension(av[1], ".cub");
}
