/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:30 by darismen          #+#    #+#             */
/*   Updated: 2024/07/31 20:33:25 by darismen         ###   ########.fr       */
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

/* void	collision(t_game *game, t_player *player)
{
	t_vec2d	*pos;
	t_vec2d	*dir;

	pos = &player->pos; //This may leak, check later.
	dir = &player->dir;
	if (game->map
		[(int)pos->y]
		[(int)(pos->x + dir->x * ceil(player->speed))] != 1)
		pos->x += (player->speed * dir->x);
	if (game->map
		[(int)(pos->y + dir->y * ceil(player->speed))]
		[(int)(pos->x)] != 1)
		pos->y += (player->speed * dir->y);
} */

void	ft_set_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
		game->player->yaw = 0;
	else if (dir == 'E')
		game->player->yaw = 90;
	else if (dir == 'S')
		game->player->yaw = 180;
	else if (dir == 'W')
		game->player->yaw = 270;
}



/* int	find_player_pos(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr("NSWE", game->map[i][j]))
			{
				game->player->pos.x = (double)j;
				game->player->pos.y = (double)i;
				ft_set_player_dir(game, game->map[i][j]);
				return (1);
			}
		}
	}
	return (0);
} */

void	ft_player_init_pos(t_player *player, char dir,
	int x, int y)
{
	player->pos.x = (double)x;
	player->pos.y = (double)y;
	if (dir == 'N')
		player->yaw = 0;
	else if (dir == 'E')
		player->yaw = 90;
	else if (dir == 'S')
		player->yaw = 180;
	else if (dir == 'W')
		player->yaw = 270;
}

/* 	if (ft_strchr("WS", cross))
		player->speed.y = lerp(0.0f, 10.0f, .5f);
	if (ft_strchr("AD", cross))
		player->speed.x = lerp(0.0f, 10.0f, .5f); */
double	get_speed(t_player *player, int cross)
{
	if (ft_strchr("WS", cross))
		player->speed.y = 10.0;
	if (ft_strchr("AD", cross))
		player->speed.x = 10.0;
	return (sqrt(player->speed.y * player->speed.y
			+ player->speed.x * player->speed.x));
}

int	movement(t_game *game, t_player *player, int sign, char cross)
{
	t_vec2d	*pos;
	t_vec2d	*dir;
	double	speed;

	pos = &player->pos; //This may leak, check later.
	dir = &player->dir;
	speed = get_speed(player, cross);
	if (ft_strchr("DA", cross))
		if (game->map
			[(int)pos->y]
			[(int)(pos->x + (dir->x * ceil(player->speed.x) * sign))] != 1)
			pos->x += (speed * dir->x * sign);
	if (ft_strchr("WS", cross))
		if (game->map
			[(int)(pos->y + (dir->y * ceil(player->speed.y) * sign))]
			[(int)(pos->x)] != 1)
			pos->y += (speed * dir->y * sign);
	return (0);
}

void	rotation(t_player *player, int dir)
{
	if (dir == 1)
	{
		player->yaw += player->rot_spd;
		if (player->yaw >= 360)
			player->yaw -= 360;
	}
	else if (dir == -1)
	{
		player->yaw -= player->rot_spd;
		if (player->yaw <= 360)
			player->yaw += 360;
	}
	player->dir.x = cos(to_rad(player->yaw));
	player->dir.y = sin(to_rad(player->yaw));
}