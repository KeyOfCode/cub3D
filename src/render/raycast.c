/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:03:52 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 12:04:19 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * Información necesaria:
 * t_game->t_player
 * -Posición del jugador t_game->t_player->pos
 * -Dirección del jugador t_game->t_player->dir
 * -Vector plano de la cámara t_game->t_player->fov
 * -Asumimos que FOV = 60º
 */

void	ft_init_dirs(t_game *game);

static void	ft_init_raycast(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir.x = player->dir.x + player->fov.x * ray->camera_x;
	ray->dir.y = player->dir.y + player->fov.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->deltadist.x = fabs(1 / ray->dir.x);
	ray->deltadist.y = fabs(1 / ray->dir.y);
}

static void	ft_set_step_directions(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (player->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - player->pos.x) * ray->deltadist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (player->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - player->pos.y) * ray->deltadist.y;
	}
}

static void	ft_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map[(int)ray->map.y][(int)ray->map.x] == '1')
		{
			hit = 1;
		}
	}
}

static void	ft_calculate_line_height(t_ray *ray, t_player *player)
{
	if (ray->side)
		ray->wall_dist = (ray->sidedist.y - ray->deltadist.y);
	else
		ray->wall_dist = (ray->sidedist.x - ray->deltadist.x);
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -((ray->line_height) / 2) + (HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

int	ft_raycast(t_game *game, t_ray *ray, uint32_t **pixel_data)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ft_init_dirs(game);
		ft_init_raycast(ray, game->player, x);
		ft_set_step_directions(ray, game->player);
		ft_dda(game, ray);
		ft_calculate_line_height(ray, game->player);
		ft_register_pixels(ray, game, pixel_data, x);
		x++;
	}
	return (EXIT_SUCCESS);
}
