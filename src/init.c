/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:53:40 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:36:28 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray(t_ray *ray);

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
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (mlx_close_window(game->mlx),
			puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	game->lst_map = NULL;
	game->textures = NULL;
	ft_init_ray(&game->ray);
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
	player->dir.modulo = 0;
	player->fov.x = 0;
	player->fov.y = 0;
	player->yaw = 0;
	player->speed = 0;
	player->rot_spd = ROT_SPD;
}

void	ft_init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step.x = 0;
	ray->step.y = 0;
	ray->sidedist.x = 0;
	ray->sidedist.y = 0;
	ray->deltadist.x = 0;
	ray->deltadist.y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_map(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
		ft_cub_error("Invalid number of arguments", game);
	if (!open_map(argv[1], game))
		ft_cub_error("Can't open map.", game);
	if (!parser(game))
		return (ft_cub_error("Parser failure.", game));
	if (!is_enclosed(game))
		return (ft_cub_error("Map is not enclosed.", game));
	if (!allowed_char(game))
		return (ft_cub_error("Has a character not allowed.", game));
	if (!required_char(game))
		return (ft_cub_error("Missing required characters.", game));
}
