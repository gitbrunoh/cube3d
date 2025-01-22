/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:38:48 by brunhenr          #+#    #+#             */
/*   Updated: 2025/01/04 21:21:56 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

long	ft_get_time_s(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_start_frame(t_frame_time *frame_time)
{
	gettimeofday(&frame_time->start, NULL);
}

void	ft_end_frame(t_frame_time *frame_time)
{
	gettimeofday(&frame_time->end, NULL);
	frame_time->frame_time = (frame_time->end.tv_sec - \
	frame_time->start.tv_sec) + \
	(frame_time->end.tv_usec - frame_time->start.tv_usec) / 1000000.0;
	frame_time->move_speed = frame_time->frame_time * MOVE_FACTOR;
	frame_time->rot_speed = frame_time->frame_time * ROTATE_FACTOR;
}
