/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:30 by darismen          #+#    #+#             */
/*   Updated: 2024/08/20 13:00:56 by darismen         ###   ########.fr       */
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

	// printf("col_speed_x = %f, col_speed_y = %f\n",
	// 	ceil(player->speed.x), ceil(player->speed.y));
	// printf("cross: %c\n", cross);
	// printf("col_pos_x = %f, ",
	// 	(pos->x + (dir->x * (player->speed.x) * sign)));
	// printf("col_pos_y = %f\n",
	// 	(pos->y + (dir->y * (player->speed.y) * sign)));

/* int	collision_W(t_game *game, t_player *player, double speed)
{
	t_vec2d	sign;
	t_vec2d	*pos;
	t_vec2d	*dir;

	pos = &player->pos;
	dir = &player->dir;
	sign.x = 1;
	sign.y = 1;
	if (dir->x < 0)
		sign.x = -1;
	if (dir->y < 0)
		sign.y = -1;
	if (game->map
		[(int)pos->y]
		[(int)((pos->x + (dir->x * speed)) + (0.2 * sign.x))] == '1')
		return (printf("x\n"));
	if (game->map
		[(int)(((pos->y + (dir->y * speed)) + (0.2 * sign.y)))]
		[(int)(pos->x)] == '1')
		return (printf("y\n"));
	return (1);
} */

/* int	collision_D(t_game *game, t_player *player, double speed)
{
	t_vec2d	sign;
	t_vec2d	*pos;
	t_vec2d	*dir;

	pos = &player->pos;
	dir = &player->dir;
	sign.x = 1;
	sign.y = 1;
	if (dir->x < 0)
		sign.x = -1;
	if (dir->y < 0)
		sign.y = -1;
	if (game->map
		[(int)pos->y]
		[(int)((pos->x + (dir->y * speed)) + (0.2 * sign.x))] == '1')
		return (printf("x"));
	if (game->map
		[(int)(((pos->y + (dir->x * speed)) + (0.2 * sign.y)))]
		[(int)(pos->x)] == '1')
		return (printf("y"));
	return (1);
} */

int	collision(t_game *game, t_player *player, int sign)
{
	t_vec2d	*pos;

	pos = &player->pos;
	if (game->map
		[(int)pos->y]
		[(int)(pos->x
			+ (player->dir.x * ceil(player->speed.x) * sign) + 0.2)] == '1')
		return (1);
	if (game->map
		[(int)(pos->y + (player->dir.y * ceil(player->speed.y) * sign) + 0.2)]
		[(int)(pos->x)] == '1')
		return (1);
	return (0);
}

	// printf("speed_x = %f, speed_y = %f\n",
	// 	(player->speed.x), (player->speed.y));
	// printf("new_map_x = %c\n", game->map
	// [(int)pos->y]
	// [(int)(pos->x + (player->dir.x * ceil(player->speed.x) * sign))]);
	// printf("new_map_y = %c\n", game->map
	// [(int)(pos->y + (player->dir.y * ceil(player->speed.y) * sign))]
	// [(int)(pos->x)]);

	// ft_printf_fd(2, "x %d, y %d\n", x, y);
	// ft_printf_fd(2, "x %d, y %d\n", (int)player->pos.x , (int)player->pos.y);

	// if (ft_strchr("WS", cross))
		// player->speed.y += lerp(0.0, SPEED, 0.1) * sign;
	// else if (ft_strchr("AD", cross))
		// player->speed.x += lerp(0.0, SPEED, 0.1) * sign;
double	get_speed(t_player *player, int cross, int sign)
{
	// (void)cross;
	if (ft_strchr("WS", cross))
		player->speed.y = 0.2 * sign;
	else if (ft_strchr("AD", cross))
		player->speed.x = 0.2 * sign;
	return (sqrt(pow(player->speed.y, 2) + pow(player->speed.x, 2)));
}

/* int	movement(t_game *game, t_player *player, int sign, char cross)
{
	double	speed;
	t_vec2d	*pos;
	t_vec2d	*dir;

	player->speed.x = SPEED * 1000000 * sign;
	pos = &player->pos;
	dir = &player->dir;
	speed = player->speed.x;
	// printf("collision: %d\n", collision(game, player, sign));
	if (cross == 'W')
	{
		if (collision_W(game, player, speed))
		{
			pos->x += (speed * dir->x);
			pos->y += (speed * dir->y);
		}
	}
	// if (cross == 'D')
	// {
	// 	if (collision_D(game, player, speed))
	// 	{
	// 		pos->x += (speed * dir->y);
	// 		pos->y += (speed * dir->x);
	// 	}
	// }
	// if (cross == 'A')
	// {
	// 	if (collision_D(game, player, speed))
	// 	{
	// 		pos->x -= (speed * dir->y);
	// 		pos->y -= (speed * dir->x);
	// 	}
	// }
	return (0);
} */

int	movement(t_game *game, t_player *player, int sign, char cross)
{
	double	speed;
	t_vec2d	*pos;
	t_vec2d	*dir;

	player->speed.x = SPEED;
	pos = &player->pos;
	dir = &player->dir;
	speed = player->speed.x;
	if (!collision(game, player, sign))
	{
		if (ft_strchr("WS", cross))
		{
			pos->y += (speed * dir->y * sign);
			pos->x += (speed * dir->x * sign);

		}
		if (ft_strchr("AD", cross))
		{
			pos->y += (speed * player->perp.y * sign);
			pos->x += (speed * player->perp.x * sign);
		}
	}
	return (0);
}
		// player->pos.x += (cos(to_rad(pos)) * sign);
		// player->pos.y += (-sin(to_rad(pos)) * sign);
// player->pos.x += (player->speed.x * player->dir.x * sign);
// player->pos.y += (player->speed.y * player->dir.y * sign);
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
	if (dir == 1)
	{
		player->yaw += ROT_SPD;
		// player->yaw += lerp(0, ROT_SPD, 1);
		if (player->yaw >= 360)
			player->yaw -= 360;
	}
	else if (dir == -1)
	{
		player->yaw -= ROT_SPD;
		// player->yaw -= lerp(0, ROT_SPD, 1);
		if (player->yaw <= 0)
			player->yaw += 360;
	}
	player->dir.x = cos(to_rad(player->yaw));
	player->dir.y = -sin(to_rad(player->yaw));
	player->perp.x = cos(to_rad(90 - player->yaw));
	player->perp.y = sin(to_rad(90 - player->yaw));
	printf("dir_x = %f, dir_y = %f, yaw = %f\n", player->dir.x,
		player->dir.y, player->yaw);
	printf("perp_x = %f, perp_y = %f\n", player->perp.x,
		player->perp.y);
}
