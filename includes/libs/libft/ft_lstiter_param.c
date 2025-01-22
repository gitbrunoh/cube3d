/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:11:33 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/09 19:11:58 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content, ptr);
		temp = temp->next;
	}
}
