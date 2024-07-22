/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:28:29 by darismen          #+#    #+#             */
/*   Updated: 2024/07/22 15:55:49 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*ft_find_texture(int type, t_texture *texture)
{
	t_texture	*head;

	head = texture;
	while (head)
	{
		if (head->type == type)
			return (head);
		head = head->next;
	}
	ft_error("Sprite could not be drawn");
	exit(EXIT_FAILURE);
}

/**
 * @brief Receives a sprite as a texture, converts it to image, 
 * and displays it.
 * 
 * @param x : x position (from the top left);
 * @param y : y position (from the top left);
 * @param sprite : texture to render;
 * @param game : game pointer;
 */
void	draw_block(int x, int y, int type, t_game *game)
{
	mlx_image_t	*image;
	t_texture	*sprite;
	int			i;

	sprite = ft_find_texture(type, game->textures);
	i = -1;
	while (++i < sprite->nb)
	{
		image = mlx_texture_to_image(game->mlx, sprite->sprites[i]);
		mlx_image_to_window(game->mlx, image, x, y);
	}
}

/* void	draw_walls_(t_game *game, int i, int j)
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
} */

void	draw_walls(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->g_height)
	{
		j = 0;
		while (j < game->max_width - 1)
		{
			if (game->map[i][j] == '1')
				draw_block(j * BPX, i * BPX,
					NO, game);
			else
				draw_block(j * BPX, i * BPX,
					SO, game);
			j++;
		}
		i++;
	}
}

			// if (game->map[i][j] == '1')
			// 	draw_walls_(game, i, j);

/* void	draw_other(t_game *game)
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
} */
