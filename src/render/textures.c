/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:22:12 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:38:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

mlx_texture_t	*set_texture(t_texture *textures, int symb, t_game *game)
{
	t_texture	*head;

	head = textures;
	while (head)
	{
		if (head->type == symb)
			return (*head->sprites);
		head = head->next;
	}
	return (ft_cub_error("set_texture Failure", game), NULL);
}

static void	ft_get_texture(t_ray *ray, t_game *game)
{
	t_texture	*textures;

	textures = game->textures;
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			ray->texture = set_texture(textures, WE, game);
		else
			ray->texture = set_texture(textures, EA, game);
	}
	else
	{
		if (ray->dir.y > 0)
			ray->texture = set_texture(textures, SO, game);
		else
			ray->texture = set_texture(textures, NO, game);
	}
}

void	ft_register_pixels(t_ray *ray, t_game *game,
	uint32_t **pixel_data, int x)
{
	t_rend			to_rend;
	int				y;
	uint32_t		color;

	ft_get_texture(ray, game);
	to_rend.x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		to_rend.x = TEX_WIDTH - to_rend.x - 1;
	to_rend.step = 1.0 * TEX_HEIGHT / ray->line_height;
	to_rend.pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * to_rend.step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		to_rend.y = (int)to_rend.pos % TEX_HEIGHT;
		to_rend.pos += to_rend.step;
		color = ft_get_color(ray->texture, to_rend.x, to_rend.y);
		if (color > 0)
			pixel_data[y][x] = color;
		y++;
	}
}
