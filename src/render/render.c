/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:12:04 by darismen          #+#    #+#             */
/*   Updated: 2024/08/12 16:30:36 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// int	get_rgba(int r, int g, int b, int a);

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

static void	ft_clean_image(mlx_image_t *image)
{
	int	i;

	i = 0;
	while (i < (WIDTH * HEIGHT * 4 - 1))
	{
		image->pixels[i] = 0;
		i++;	
	}
}

static void	set_pixel(uint32_t **pixel_data, mlx_image_t *image, int x, int y)
{
	int	ceiling;
	int	floor;

	floor = get_rgba(205, 225, 254, 255);
	ceiling = get_rgba(255,248,220,255);
	if (pixel_data[y][x] > 0)
		mlx_put_pixel(image, x, y, pixel_data[y][x]);
	else if (y > HEIGHT / 2)
		mlx_put_pixel(image, x, y, ceiling);
	else if (y < HEIGHT / 2)
		mlx_put_pixel(image, x, y, floor);
}

static void	ft_render_frame(t_game *game, uint32_t **pixels)
{
	int				x;
	int				y;

	ft_clean_image(*game->img);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_pixel(pixels, *game->img, x, y);
			x++;
		}
		y++;
	}
}

static uint32_t	**ft_init_pixels(void)
{
	uint32_t	**result; 
	int	i;

	result = ft_calloc(HEIGHT,
			sizeof(int **));
/* 	if (!result)
		ft_exit_error(game); */
	i = 0;
	while (i < HEIGHT)
	{
		result[i] = ft_calloc(WIDTH + 1,
				sizeof (uint32_t *));
		/* 	if (!result[i])
			ft_exit_error(game); */
		i++;
	}
	return (result);
}

int ft_render(t_game *game)
{
	uint32_t	**pixel_data;
	t_ray 		ray;

	pixel_data = ft_init_pixels();
	ft_init_ray(&ray);
	ft_raycast(game, &ray, pixel_data);
	// ft_printf_fd(2, "Segfaults!\n");
	ft_render_frame(game, pixel_data);
	return (EXIT_SUCCESS);
}