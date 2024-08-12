/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:53:40 by darismen          #+#    #+#             */
/*   Updated: 2024/08/12 15:47:44 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	game->max_width = -1;
	game->g_height = -1;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->img[0] = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img[0])
		return (mlx_close_window(game->mlx),
			puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	game->lst_map = NULL;
	game->textures = NULL;
	return (1);
}

int	open_map(char *relative_path, t_game *game)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(&relative_path[path_len - 4], ".cub", 4) != 0)
		return (0);
	game->map_fd = open(relative_path, O_RDONLY);
	if (game->map_fd < 0)
		return (0);
	return (1);
}

void	init_player(t_player *player)
{
	player->pos.x = -1.0;
	player->pos.y = -1.0;
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
	// ft_error("Parser");
	if (!parser(game))
		ft_cub_error(3);
	// ft_error("Parser Finished");
	// ft_error("Is Enclosed");
	if (!is_enclosed(game))
		ft_cub_error(3);
	// ft_error("Is Enclosed Finished");
	// ft_error("Allowed Char");
	if (!allowed_char(game))
		ft_cub_error(3);
	// ft_error("Allowed Char Finished");
	// ft_error("Required Char");
	if (!required_char(game))
		ft_cub_error(3);
	// ft_error("Required Char Finished");
	return (1);
}

/* 
ft_error("Textures Init");
	if (!init_texture_lst(game))
		ft_cub_error(5);
	ft_error("Textures Init Finished");
	ft_error("Map Init");
	if (!fill_lst(game))
		ft_cub_error(3);
	ft_error("Map Init Finished");
	ft_error("Convert Map");
	if (!convert_lst(game))
		ft_cub_error(3);
 */