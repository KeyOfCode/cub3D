/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:11 by darismen          #+#    #+#             */
/*   Updated: 2024/08/13 10:36:00 by darismen         ###   ########.fr       */
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

/* void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		*i += 1;
} */

float	lerp(float a, float b, float f)
{
	return (a * (1.0 - f) + (b * f));
}

float	to_rad(float degree)
{
	return (degree * (M_PI / 180));
}

/* void	resize_map(t_game *game)
{
	if (!(game->max_width * BPX > WIDTH || game->g_height * BPX > HEIGHT))
		mlx_set_window_size(game->mlx,
			(game->max_width) * BPX, game->g_height * BPX);
} */

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
