/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amount_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:18:17 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 13:20:32 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_amount_char(char *str, char c)
{
	int	amount;
	int	i;

	amount = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			amount++;
	return (amount);
}
