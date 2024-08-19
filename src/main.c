/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:15:50 by darismen          #+#    #+#             */
/*   Updated: 2024/08/19 12:49:10 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void leaks()
{
	system("leaks -q so_long");
} */

void	ft_cub_error(char *err)
{
	ft_error("Error!");
	ft_error(err);
	exit(EXIT_SUCCESS);
}

void	game_loop(void *param)
{
	t_game		*game;

	game = param;
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	ft_render(game);
	(void)game;
}

// int	main()
int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	(void)argc;
	game = (t_game *)malloc(sizeof(t_game));
	if (!init_game(game))
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	init_player(game->player);
	init_map(argc, argv, game);
	init_sprites(game);
	hook_register(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	exit(EXIT_SUCCESS);
}

	// resize_map(game);
	// ft_print_map(game);
	// draw_walls(game);
	// draw_other(game);
	// draw_player(game);
