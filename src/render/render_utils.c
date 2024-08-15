/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:26:27 by darismen          #+#    #+#             */
/*   Updated: 2024/08/15 13:56:38 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_init_dirs(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->dir.x = cos(to_rad(player->yaw));
	player->dir.y = -sin(to_rad(player->yaw));
	player->fov.x = player->dir.y * -0.66;
	player->fov.y = player->dir.x * 0.66;
	// printf("dir x: %f, dir y: %f, fov x: %f, fov y: %f\n",
	// 	player->dir.x, player->dir.y, player->fov.x, player->fov.y);
}

/* void	ft_init_dirs(t_game *game)
{
	// printf("%f\n", game->player->yaw);
	if (game->player->yaw == 0)
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
		game->player->fov.x = 0;
		game->player->fov.y = -0.66;
	}
	else if (game->player->yaw == 90)
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
		game->player->fov.x = 0.66;
		game->player->fov.y = 0;
	}
	else if (game->player->yaw == 180)
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
		game->player->fov.x = 0;
		game->player->fov.y = 0.66;
	}
	else if (game->player->yaw == 270)
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
		game->player->fov.x = -0.66;
		game->player->fov.y = 0;
	}
} */
