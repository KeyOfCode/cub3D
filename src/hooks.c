/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:29 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 11:58:41 by darismen         ###   ########.fr       */
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

void	current_key(void *param)
{
	t_game	*game;

	game = param;
	if (game->keys.w)
		movement(game, game->player, 1, 'W');
	if (game->keys.s)
		movement(game, game->player, -1, 'S');
	if (game->keys.d)
		movement(game, game->player, 1, 'D');
	if (game->keys.a)
		movement(game, game->player, -1, 'A');
	if (game->keys.right_arrow)
		rotation(game->player, -1);
	if (game->keys.left_arrow)
		rotation(game->player, 1);
}

void	hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		pressed;

	game = param;
	pressed = (keydata.action != MLX_RELEASE);
	if (pressed)
		press_hooks(keydata, game);
	else
		release_hooks(keydata, game);
	current_key(game);
}

void	hook_register(t_game *game)
{
	init_keys(game);
	mlx_key_hook(game->mlx, &hooks, game);
}
