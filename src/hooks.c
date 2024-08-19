/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:29 by darismen          #+#    #+#             */
/*   Updated: 2024/08/19 14:22:16 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

/* void	ft_free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_delete_texture(game->os[i++]);
	i = 0;
	while (i < 4)
		mlx_delete_texture(game->ps[i++]);
	i = 0;
	while (i < 2)
		mlx_delete_texture(game->gs[i++]);
	i = 0;
	// if (game->nc != 0)
	// 	mlx_delete_image(game->mlx, game->img[COIN]);
	while (i < IMG_COUNT)
		if (game->img[i])
			mlx_delete_image(game->mlx, game->img[i++]);
} */

void	exit_game(t_game *game)
{
	mlx_close_window(game->mlx);
	// ft_free_textures(game);
	mlx_terminate(game->mlx);
	ft_2darrfree((void **)game->map);
	ft_lstclear(&game->lst_map, free);
	free(game->player);
	free(game);
	ft_printf_fd(1, "\nGame Ended succesfully\n");
	exit(EXIT_SUCCESS);
}

void	stop_player(t_player *playyer)
{
	playyer->speed.x = 0;
	playyer->speed.y = 0;
}

void	hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		pressed;

	game = param;
	pressed = (keydata.action != MLX_RELEASE);
	if (keydata.key == (MLX_KEY_ESCAPE))
		exit_game(game);
	if (pressed)
	{
		printf("\nold_pos_x = %f, old_pos_y = %f old_map = %c\n",
			game->player->pos.x, game->player->pos.y,
			game->map[(int)game->player->pos.y][(int)game->player->pos.x]);
		if (keydata.key == MLX_KEY_RIGHT)
			rotation(game->player, 1);
		if (keydata.key == MLX_KEY_LEFT)
			rotation(game->player, -1);
		if (keydata.key == MLX_KEY_W)
			movement(game, game->player, 1, 'W');
		if (keydata.key == MLX_KEY_S)
			movement(game, game->player, -1, 'S');
		if (keydata.key == MLX_KEY_D)
			movement(game, game->player, 1, 'D');
		if (keydata.key == MLX_KEY_A)
			movement(game, game->player, -1, 'A');
		printf("new_pos_x = %f, new_pos_y = %f new_map = %c\n",
			game->player->pos.x, game->player->pos.y,
			game->map[(int)game->player->pos.y][(int)game->player->pos.x]);
	}
	else if (!pressed)
		stop_player(game->player);
}

void	hook_register(t_game *game)
{
	mlx_key_hook(game->mlx, &hooks, game);
}
