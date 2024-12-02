/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:08:00 by brunhenr          #+#    #+#             */
/*   Updated: 2024/12/02 19:53:35 by brunhenr         ###   ########.fr       */
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

static void	ft_validate_extension(char *name)
{
	int	len;

	len = ft_strlen(name);
	while (len > 0)
	{
		if (name[len] == '.')
		{
			if (ft_strcmp(&name[len], ".cub") == 0)
				return ;
			else
				ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
		}
		len--;
	}
	ERROR_PRINT(ERROR_MSG(4, ERROR_EXT, name, "\"\n"), 1);
}

void	ft_input_validation(char **av, int ac)
{
	ft_validate_arguments(ac);
	ft_validate_extension(av[1]);
}
