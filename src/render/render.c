/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:12:04 by darismen          #+#    #+#             */
/*   Updated: 2024/08/27 15:51:23 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_init_ray(t_ray *ray)
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

static void	set_pixel(uint32_t **pixel_data, t_game *game, int x, int y)
{
	int	ceiling;
	int	floor;

	// floor = get_rgba(205, 225, 254, 255);
	// ceiling = get_rgba(255, 248, 220, 255);
	floor = get_rgba(game->floor[0], game->floor[1],
			game->floor[2], 255);
	ceiling = get_rgba(game->ceiling[0], game->ceiling[1],
			game->ceiling[2], 255);
	if (pixel_data[y][x] > 0)
		mlx_put_pixel(game->img, x, y, pixel_data[y][x]);
	else if (y > HEIGHT / 2)
		mlx_put_pixel(game->img, x, y, ceiling);
	else if (y < HEIGHT / 2)
		mlx_put_pixel(game->img, x, y, floor);
}

static void	ft_render_frame(t_game *game, uint32_t **pixels)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_pixel(pixels, game, x, y);
			x++;
		}
		y++;
	}
}

static void ft_free_pixels(uint32_t **pixel_data)
{
	int i;

	i = 0;
	while (i < HEIGHT)
	{
		free(pixel_data[i]);
		i++;
	}
	free(pixel_data);
}

static uint32_t	**ft_init_pixels(void)
{
	uint32_t	**result;
	int			i;

	result = ft_calloc(HEIGHT, sizeof(int **));
	i = 0;
	while (i < HEIGHT)
	{
		result[i] = ft_calloc(WIDTH + 1,
				sizeof (uint32_t *));
		i++;
	}
	return (result);
}

int	ft_render(t_game *game)
{
	uint32_t	**pixel_data;
	t_ray		ray;
	// t_player	*player;

	// player = game->player;
	// if (game->map[(int)player->pos.y][(int)player->pos.x] == '1')
	// 	return (EXIT_SUCCESS);
	pixel_data = ft_init_pixels();
	ft_init_ray(&ray);
	ft_raycast(game, &ray, pixel_data);
	ft_render_frame(game, pixel_data);
	ft_free_pixels(pixel_data);
	return (EXIT_SUCCESS);
}