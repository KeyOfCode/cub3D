/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:30 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 12:06:54 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	collisionx(t_game *game, t_player *player, t_vec2d vector, int sign)
{
	t_vec2d	*pos;
	float	tol;

	pos = &player->pos;
	tol = TOLERANCE;
	if ((vector.x * sign) < 0)
		tol *= -1;
	if (game->map
		[(int)pos->y]
		[(int)(pos->x
			+ (vector.x * round(player->speed) * sign) + tol)] == '1')
		return (1);
	return (0);
}

int	collisiony(t_game *game, t_player *player, t_vec2d vector, int sign)
{
	t_vec2d	*pos;
	float	tol;

	pos = &player->pos;
	tol = TOLERANCE;
	if ((vector.y * sign) < 0)
		tol *= -1;
	if (game->map
		[(int)(pos->y + (vector.y * round(player->speed) * sign) + tol)]
		[(int)(pos->x)] == '1')
		return (1);
	return (0);
}

int	movement(t_game *game, t_player *player, int sign, char cross)
{
	double	speed;
	t_vec2d	*pos;
	t_vec2d	*dir;

	if (player->speed < 0.4)
		player->speed = lerp(player->speed, SPEED, 0.1 * game->mlx->delta_time);
	pos = &player->pos;
	dir = &player->dir;
	speed = player->speed;
	if (ft_strchr("WS", cross))
	{
		if (!collisiony(game, player, player->dir, sign))
			pos->y += (speed * dir->y * sign);
		if (!collisionx(game, player, player->dir, sign))
			pos->x += (speed * dir->x * sign);
	}
	if (ft_strchr("AD", cross))
	{
		if (!collisiony(game, player, player->perp, sign))
			pos->y += (speed * player->perp.y * sign);
		if (!collisionx(game, player, player->perp, sign))
			pos->x += (speed * player->perp.x * sign);
	}
	return (0);
}

void	rotation(t_player *player, int dir)
{
	if (dir == 1)
	{
		player->yaw += ROT_SPD;
		if (player->yaw >= 360)
			player->yaw -= 360;
	}
	else if (dir == -1)
	{
		player->yaw -= ROT_SPD;
		if (player->yaw <= 0)
			player->yaw += 360;
	}
	player->dir.x = cos(to_rad(player->yaw));
	player->dir.y = -sin(to_rad(player->yaw));
	player->perp.x = cos(to_rad(90 - player->yaw));
	player->perp.y = sin(to_rad(90 - player->yaw));
}
