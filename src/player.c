/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:30 by darismen          #+#    #+#             */
/*   Updated: 2024/08/19 13:52:53 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if there's a wall in the direction is moving. 
 * If not, update position variable
 * (placed here due to function size issues...)
 * 
 * @param game 
 * @param pos 
 * @param dir 
 * @return int 
 */
/* int	so_long_wall_collision(t_game *game, int *pos, char dir)
{
	if (dir == 'S' && !(game->map[pos[Y] + 1][pos[X]] == '1'))
		return (pos[Y]++, 0);
	if (dir == 'W' && !(game->map[pos[Y] - 1][pos[X]] == '1'))
		return (pos[Y]--, 0);
	if (dir == 'D' && !(game->map[pos[Y]][pos[X] + 1] == '1'))
		return (pos[X]++, 0);
	if (dir == 'A' && !(game->map[pos[Y]][pos[X] - 1] == '1'))
		return (pos[X]--, 0);
	return (1);
} */

double	get_speed(t_player *player, int cross, int sign);

int	collision(t_game *game, t_player *player, int sign, char cross)
{
	t_vec2d	*pos;
	t_vec2d	*dir;
	// double speed = get_speed(player, cross, sign);

	pos = &player->pos;
	dir = &player->dir;
	(void)cross;
	// printf("col_speed_x = %f, col_speed_y = %f\n",
	// 	ceil(player->speed.x), ceil(player->speed.y));
	printf("cross: %c\n", cross);
	printf("col_pos_x = %f, col_pos_y = %f\n",
		(pos->x + (dir->x * (player->speed.x) * sign)),
		(pos->y + (dir->y * (player->speed.y) * sign)));
	if (game->map
		[(int)pos->y]
		[(int)(pos->x + (dir->x * ceil(player->speed.x) * sign))] != '1')
		return (0);
	if (game->map
		[(int)(pos->y + (dir->y * ceil(player->speed.y) * sign))]
		[(int)(pos->x)] != '1')
		return (0);
	return (1);
}

	// ft_printf_fd(2, "x %d, y %d\n", x, y);
	// ft_printf_fd(2, "x %d, y %d\n", (int)player->pos.x , (int)player->pos.y);

	// if (ft_strchr("WS", cross))
		// player->speed.y += lerp(0.0, SPEED, 0.1) * sign;
	// else if (ft_strchr("AD", cross))
		// player->speed.x += lerp(0.0, SPEED, 0.1) * sign;
double	get_speed(t_player *player, int cross, int sign)
{
	(void)cross;
	// if (ft_strchr("WS", cross))
		player->speed.y += 0.2 * sign;
	// else if (ft_strchr("AD", cross))
		player->speed.x += 0.2 * sign;
	return (sqrt(pow(player->speed.y, 2) + pow(player->speed.x, 2)));
}

int	movement(t_game *game, t_player *player, int sign, char cross)
{
	t_vec2d	*pos;
	t_vec2d	*dir;
	double	speed;

	(void)game;
	pos = &player->pos;
	dir = &player->dir;
	// printf("speed_x = %f, speed_y = %f\n",
		// (player->speed.x), (player->speed.y));
	speed = get_speed(player, cross, sign);
	printf("collision: %d\n",collision(game, player, sign, cross));
	if (!collision(game, player, sign, cross))
	{
		pos->x += (speed * dir->x * sign);
		pos->y += (speed * dir->y * sign);
	}
	return (0);
}
/* 
void	move_pos(t_player *player, char cross, double *move_x, double *move_y)
{
	if (cross == 'D') //move right
	{
		*move_x = -sin(player->yaw) * SPEED;
		*move_y = cos(player->yaw) * SPEED;
	}
	if (cross == 'A') //move left
	{
		*move_x = sin(player->yaw) * SPEED;
		*move_y = -cos(player->yaw) * SPEED;
	}
	if (cross == 'W') //move up
	{
		*move_x = cos(player->yaw) * SPEED;
		*move_y = sin(player->yaw) * SPEED;
	}
	if (cross == 'S') //move down
	{
		*move_x = -cos(player->yaw) * SPEED;
		*move_y = -sin(player->yaw) * SPEED;
	}
	move_player(move_x, move_y); // move the player
}
 */

/* int	movement(t_game *game, t_player *player, int sign, char cross)
{
	t_vec2d	*pos;
	t_vec2d	*dir;
	double	speed;

	sign *= -1;
	pos = &player->pos;
	dir = &player->dir;
	speed = get_speed(player, cross);
	if (ft_strchr("WS", cross))
		if (game->map
			[(int)pos->y]
			[(int)(pos->x + (dir->x * ceil(player->speed.x) * sign))] != 1)
			pos->x += (speed * dir->x * sign);
	if (ft_strchr("DA", cross))
		if (game->map
			[(int)(pos->y + (dir->y * ceil(player->speed.y) * sign))]
			[(int)(pos->x)] != 1)
			pos->y += (speed * dir->y * sign);
	return (0);
} */

void	rotation(t_player *player, int dir)
{
	dir *= -1;
	if (dir == 1)
	{
		player->yaw += player->rot_spd;
		// player->yaw += lerp(player->yaw, player->yaw + 1, 0.1 * timestamp());
		if (player->yaw >= 360)
			player->yaw -= 360;
	}
	else if (dir == -1)
	{
		player->yaw -= player->rot_spd;
		// player->yaw -= lerp(player->yaw, player->yaw - 1, 0.1 * timestamp());
		if (player->yaw <= 360)
			player->yaw += 360;
	}
	player->dir.x = cos(to_rad(player->yaw));
	player->dir.y = -sin(to_rad(player->yaw));
		// printf("dir_x = %f, dir_y = %f\n", game->player->dir.x,
	// 	game->player->dir.y);
}
