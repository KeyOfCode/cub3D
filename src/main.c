/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:15:50 by darismen          #+#    #+#             */
/*   Updated: 2024/07/31 18:48:49 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void leaks()
{
	system("leaks -q so_long");
} */

void	ft_cub_error(int type)
{
	if (type == 1)
		ft_error("Error \nIncorrect number of arguments!");
	if (type == 2)
		ft_error("Error \nUnable to open the map!");
	if (type == 3)
		ft_error("Error \nThe map is not in a valid format!");
	if (type == 4)
		ft_error("Error \nA sprite could not be opened !");
	if (type == 5)
		ft_error("Error \nFATAL ERROR!");
	exit(EXIT_SUCCESS);
}

void	game_loop(void *param)
{
	t_game		*game;

	game = param;
	(void)game;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!init_game(game))
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	// init_game(game);
	// (void)argc;
	// (void)argv;
	init_map(argc, argv, game);
	resize_map(game);
	init_sprites(game);
	init_player(game->player);
	draw_walls(game);
	// draw_other(game);
	// draw_player(game);
	hook_register(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	exit(EXIT_SUCCESS);
}
