/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:29 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 11:54:27 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_keys(t_game *game)
{
	game->keys.w = FALSE;
	game->keys.s = FALSE;
	game->keys.a = FALSE;
	game->keys.d = FALSE;
	game->keys.c = TRUE;
	game->keys.right_arrow = FALSE;
	game->keys.left_arrow = FALSE;
	game->keys.shift = FALSE;
	game->keys.mouse_x = -1;
}

void	stop_player(t_player *player)
{
	player->speed = 0.0;
}

void	loop_hooks(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement(game, game->player, 1, 'W');
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement(game, game->player, -1, 'S');
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement(game, game->player, 1, 'D');
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement(game, game->player, -1, 'A');
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotation(game->player, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotation(game->player, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit_game(game);
}

void	hook_register(t_game *game)
{
	init_keys(game);
	mlx_loop_hook(game->mlx, &loop_hooks, game);
}
