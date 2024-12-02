/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:58:57 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/27 17:31:52 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

char	*ft_error_msg_construct(int nbr, ...)
{
	va_list	arg;
	int		i;
	char	*error_msg;

	error_msg = ft_strdup("");
	i = -1;
	va_start(arg, nbr);
	while (++i < nbr)
		error_msg = ft_strjoin_free(error_msg, va_arg(arg, char *));
	va_end(arg);
	return (error_msg);
}

int	ft_put_error_msg(char *error_msg, int exit_status)
{
	if (error_msg)
		ft_putstr_fd(error_msg, STDERR_FILENO);
	free(error_msg);
	ft_clear_cub();
	exit (exit_status);
}
