/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:12:14 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 12:00:18 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint64_t	timestamp(void)
{
	static struct timeval	start;
	struct timeval			tv;
	uint64_t				time;

	gettimeofday(&tv, NULL);
	if (!start.tv_sec && !start.tv_usec)
		start = tv;
	time = ((tv.tv_sec - start.tv_sec) * 1000)
		+ ((tv.tv_usec - start.tv_usec) / 1000);
	return (time);
}
