/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:28:29 by darismen          #+#    #+#             */
/*   Updated: 2024/07/19 10:48:56 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Receives a sprite as a texture, converts it to image, 
 * and displays it.
 * 
 * @param x : x position (from the top left);
 * @param y : y position (from the top left);
 * @param sprite : texture to render;
 * @param game : game pointer;
 */
void	draw_block(int x, int y, mlx_texture_t *sprite, t_game *game)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(game->mlx, sprite);
	mlx_image_to_window(game->mlx, image, x, y);
}

void	draw_walls(t_game *game, int i, int j)
{
	if (i == 0 && (j == 0 || j == game->max_width - 2))
		draw_block(j * BPX, i * BPX,
			game->os[wall2], game);
	else if (i != 0 && (j == 0 || j == game->max_width - 2)
		&& i < game->g_height - 1)
		draw_block(j * BPX, i * BPX,
			game->os[wall2], game);
	else
		draw_block(j * BPX, i * BPX,
			game->os[wall1], game);
}

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->g_height)
	{
		j = 0;
		while (j < game->max_width - 1)
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'M' || game->map[i][j] == 'P')
				draw_block(j * BPX, i * BPX,
					game->os[bg1], game);
			else if (game->map[i][j] == '1')
				draw_walls(game, i, j);
			j++;
		}
		i++;
	}
}

void	draw_other(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->img[GATE] = mlx_texture_to_image(game->mlx, game->gs[0]);
	while (i < game->g_height)
	{
		j = 0;
		while (j < game->max_width - 1)
		{
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img[COIN],
					j * BPX, i * BPX);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->img[GATE],
					j * BPX, i * BPX);
			j++;
		}
		i++;
	}
}
