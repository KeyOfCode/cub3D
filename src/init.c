/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:53:40 by darismen          #+#    #+#             */
/*   Updated: 2024/07/22 16:47:32 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		ft_cub_error(5);
	game->max_width = -1;
	game->g_height = -1;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->img[0] = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->lst_map = NULL;
	game->textures = ft_calloc(sizeof(t_texture), 4);
	ft_error("Game init");
}

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->dir.x = 0;
	player->dir.y = 0;
	player->fov.x = 0;
	player->fov.y = 0;
	player->yaw = 0;
	player->pitch = 0;
	player->speed.x = 0;
	player->speed.y = 0;
	player->rot_spd = ROT_SPD;
}

int	init_map(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
		ft_cub_error(1);
	if (!open_map(argv[1], game))
		ft_cub_error(2);
	if (!fill_lst(game))
		ft_cub_error(3);
	ft_error("Map Init");
	if (!convert_lst(game))
		ft_cub_error(3);
	if (!is_enclosed(game))
		ft_cub_error(3);
	if (!allowed_char(game))
		ft_cub_error(3);
	// if (!sides_is_wall(game))
	// 	ft_cub_error(3);
	if (!required_char(game))
		ft_cub_error(3);
	// if (!path_to_exit(game))
	// 	ft_cub_error(3);
	return (1);
}


