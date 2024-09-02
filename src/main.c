/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:15:50 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 12:09:47 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cub_error(char *err, t_game *game)
{
	ft_error("Error!");
	ft_error(err);
	exit_game(game);
	exit(EXIT_SUCCESS);
}

void	game_loop(void *param)
{
	t_game		*game;

	game = param;
	ft_render(game);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	(void)argv;
	(void)argc;
	game = ft_calloc(sizeof(t_game), 1);
	if (!init_game(game))
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	init_player(game->player);
	init_map(argc, argv, game);
	init_sprites(game);
	hook_register(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	exit_game(game);
	exit(EXIT_SUCCESS);
}

	// resize_map(game);
	// ft_print_map(game);
	// draw_walls(game);
	// draw_other(game);
	// draw_player(game);
