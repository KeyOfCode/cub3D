#include <cub3d.h>

static void	ft_get_texture(t_ray *ray, t_game game)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			'WEST';
		else
			'EAST';
	}
	else
	{
		if (ray->dir.y > 0)
			'SOUTH';
		else
			'NORTH';
	}
}

void	ft_draw_pixels(t_ray *ray, t_player player, t_game game)
{
	t_rend	to_rend;
	int 	y;
	int		color;

	ft_get_texture(ray, game);
	to_rend.x = (int)(ray->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		to_rend.x = TEX_WIDTH - to_rend.x - 1;
	to_rend.step = 1.0 * TEX_HEIGHT / ray->line_height;
	to_rend.pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * to_rend.step;
	y = ray->draw_start;
	while (y < ray->draw_end) 
	{
		to_rend.y = (int)to_rend.pos & (TEX_HEIGHT - 1);
		to_rend.pos += to_rend.step;
		color = ft_get_color(texture, to_rend.x, to_rend.y);
		if (ray->side == 1) 
			color = (color >> 1) & 8355711;
		if (color > 0)
/* 			data->texture_pixels[to_rend.y][to_rend.x] = color; */
		y++;
	}
}
