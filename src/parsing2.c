/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:49:44 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 12:46:14 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Checks the allowed characters
int	allowed_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr("01NSEW \n", game->map[i][j]) == 0)
				return (0);
		}
	}
	return (1);
}

void	ft_player_init_pos(t_game *game, char dir, int x, int y)
{
	t_player	*player;

	player = game->player;
	player->pos.x = (double)x + 0.5;
	player->pos.y = (double)y + 0.5;
	if (dir == 'N')
		player->yaw = 90;
	else if (dir == 'E')
		player->yaw = 0;
	else if (dir == 'S')
		player->yaw = 270;
	else if (dir == 'W')
		player->yaw = 180;
	player->perp.x = cos(to_rad(90 - player->yaw));
	player->perp.y = sin(to_rad(90 - player->yaw));
}

int	required_char(t_game *game)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	check = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (ft_strchr("NSWE", game->map[i][j]))
				if (++check == 1)
					ft_player_init_pos(game, game->map[i][j], j, i);
	}
	if (check != 1)
		return (0);
	return (1);
}
