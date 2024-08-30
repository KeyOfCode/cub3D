/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:29 by darismen          #+#    #+#             */
/*   Updated: 2024/08/27 12:08:00 by darismen         ###   ########.fr       */
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

void	exit_game(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	ft_2darrfree((void **)game->map);
	ft_lstclear(&game->lst_map, free);
	free(game->player);
	free(game);
	ft_printf_fd(1, "\nGame Ended succesfully\n");
	exit(EXIT_SUCCESS);
}

void	stop_player(t_player *player)
{
	player->speed = 0.0;
}

void	press_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == (MLX_KEY_ESCAPE))
		exit_game(game);
	if (keydata.key == MLX_KEY_W)
		game->keys.w = TRUE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = TRUE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = TRUE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = TRUE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right_arrow = TRUE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left_arrow = TRUE;
}

void	release_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W)
		game->keys.w = FALSE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = FALSE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = FALSE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = FALSE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right_arrow = FALSE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left_arrow = FALSE;
	stop_player(game->player);
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

/* mlx_mousefunc mouse_hook(void *param)
{
	t_game	*game;

	game = param;
} */

/* void	hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		pressed;

	game = param;
	pressed = (keydata.action != MLX_RELEASE);
	mlx_is_key_down(game->mlx, MLX_KEY_W);
	if (keydata.key == (MLX_KEY_ESCAPE))
		exit_game(game);
	if (pressed)
	{
		if (keydata.key == MLX_KEY_RIGHT)
			rotation(game->player, -1);
		if (keydata.key == MLX_KEY_LEFT)
			rotation(game->player, 1);
		if (keydata.key == MLX_KEY_W)
			movement(game, game->player, 1, 'W');
		if (keydata.key == MLX_KEY_S)
			movement(game, game->player, -1, 'S');
		if (keydata.key == MLX_KEY_D)
			movement(game, game->player, 1, 'D');
		if (keydata.key == MLX_KEY_A)
			movement(game, game->player, -1, 'A');
	}
	else if (!pressed)
		stop_player(game->player);
} */

		// printf("\nold_pos_x = %f, old_pos_y = %f old_map = %c\n",
		// 	game->player->pos.x, game->player->pos.y,
		// 	game->map[(int)game->player->pos.y][(int)game->player->pos.x]);
		// printf("new_pos_x = %f, new_pos_y = %f new_map = %c\n",
		// 	game->player->pos.x, game->player->pos.y,
		// 	game->map[(int)game->player->pos.y][(int)game->player->pos.x]);

void	hook_register(t_game *game)
{
	init_keys(game);
	mlx_key_hook(game->mlx, &hooks, game);
	// mlx_loop_hook(game->mlx, &press_hooks, game);
	// mlx_loop_hook(game->mlx, &release_hooks, game);
	// mlx_mouse_hook(game->mlx, mouse_hook, game);
}
