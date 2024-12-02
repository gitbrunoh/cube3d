/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:29:35 by ncampbel          #+#    #+#             */
/*   Updated: 2024/03/13 18:11:01 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_buffclear(char *buff)
{
	int	i;
	int	bufflen;
	int	until_n;
	int	verify;

	i = 0;
	verify = 0;
	until_n = 0;
	bufflen = ft_strlen_gnl(buff);
	while (buff[until_n] != '\n' && buff[until_n] != '\0')
		until_n++;
	if (buff[until_n] == '\n')
		verify = 1;
	while (i < bufflen)
	{
		if (until_n + i < bufflen)
		{
			buff[i] = buff[until_n + i + 1];
			buff[until_n + i + 1] = '\0';
		}
		else
			buff[i] = '\0';
		i++;
	}
	return (verify);
}

char	*ft_strcut(char *line, char look_for)
{
	int	i;

	i = 0;
	while (line[i] != look_for && line[i] != '\0')
		i++;
	if (line[i] == look_for)
		line[++i] = '\0';
	return (line);
}

char	*ft_strjoin_gnl(char *line, char *buff)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen_gnl(line) + ft_strlen_gnl(buff);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line != NULL && line[j] != '\0')
		new[i++] = line[j++];
	j = 0;
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[i] = '\0';
	free(line);
	return (ft_strcut(new, '\n'));
}
