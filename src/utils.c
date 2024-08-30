/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:11 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 11:54:02 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_width(int width)
{
	static int	old = -1;

	if (width < old)
		width = old;
	old = width;
	return (width);
}

double	lerp(double start, double end, double rate)
{
	return (start * (1.0 - rate) + (end * rate));
}

float	to_rad(float degree)
{
	return (degree * (M_PI / 180));
}

int	ft_2darr_len(void **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return (0);
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

void	ft_2darrfree(void **arr)
{
	int	len;
	int	i;

	if (!arr)
		return ;
	len = ft_2darr_len((void **)arr);
	i = 0;
	while (i < len)
		free(arr[i++]);
	if (arr)
		free(arr);
}
