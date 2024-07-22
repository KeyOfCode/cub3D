/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:57:45 by darismen          #+#    #+#             */
/*   Updated: 2024/07/19 10:48:56 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

void	resize_map(t_game *game)
{
	if (!(game->max_width * BPX > WIDTH || game->g_height * BPX > HEIGHT))
		mlx_set_window_size(game->mlx, (game->max_width - 1) * BPX, game->g_height * BPX);
}

int	ft_2darr_len(void **arr)
{
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

void	ft_2darrfree(void **arr)
{
	int	len;
	int	i;

	len = ft_2darr_len((void **)arr);
	i = 0;
	while (i < len)
		free(arr[i++]);
	if (arr)
		free(arr);
}
