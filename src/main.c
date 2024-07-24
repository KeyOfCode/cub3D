/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:15:50 by darismen          #+#    #+#             */
/*   Updated: 2024/07/24 13:18:25 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* void leaks()
{
	system("leaks -q so_long");
} */

void	ft_cub_error(int type)
{
	if (type == 1)
		ft_putendl_fd("Error \nIncorrect number of arguments!", 2);
	if (type == 2)
		ft_putendl_fd("Error \nUnable to open the map!", 2);
	if (type == 3)
		ft_putendl_fd("Error \nThe map is not in a valid format!", 2);
	if (type == 4)
		ft_putendl_fd("Error \nA sprite could not be opened !", 2);
	if (type == 5)
		ft_putendl_fd("Error \nFATAL ERROR!", 2);
	exit(EXIT_SUCCESS);
}

void	game_loop(void *param)
{
	t_game		*game;

	game = param;
	(void)game;
}

/* int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mlx_texture_t* texture = mlx_load_png("./src/test.png");

	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	init_game(game);
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
} */
// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/* void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
} */

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(6000, 4000, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 6000, 4000)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_texture_t *texture = mlx_load_png("./src/test.png");
	
	int color = ft_pixel(texture->pixels[2000 * 6000 *4 + 100], texture->pixels[2000 * 6000 *4 + 101], texture->pixels[2000 * 6000 *4 + 102], texture->pixels[2000 * 6000 * 4 + 103]);
	for (int k=0; k < 100; k++)
		mlx_put_pixel(image, 0, k, color);
	int color2 = ft_pixel(texture->pixels[3000 * 4 + 0], texture->pixels[3000 * 4 + 1], texture->pixels[3000 * 4 + 2], texture->pixels[3000 * 4 + 3]);
	for (int k=0; k < 100; k++)
		mlx_put_pixel(image, 10, k, color2);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
