/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:26:27 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 12:12:19 by darismen         ###   ########.fr       */
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
}
