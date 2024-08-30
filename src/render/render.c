/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:12:04 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 11:14:39 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_pixel(uint32_t **pixel_data, t_game *game, int x, int y)
{
	int	ceiling;
	int	floor;

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

static void	ft_free_pixels(uint32_t **pixel_data)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(pixel_data[i]);
		i++;
	}
	free(pixel_data);
}

int	ft_render(t_game *game)
{
	uint32_t	**pixel_data;
	t_ray		ray;

	pixel_data = ft_init_pixels();
	ft_raycast(game, &ray, pixel_data);
	ft_render_frame(game, pixel_data);
	ft_free_pixels(pixel_data);
	return (EXIT_SUCCESS);
}

	// pixel_data = ft_init_pixels();
	// ft_init_ray(&ray);
