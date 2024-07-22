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
	int 	y;
	int		textureX;
	int		textureY;
	int		color;
	double	step;
	double	tex_pos;

	ft_get_texture(ray, game);
	textureX = (int)(ray->wall_x * texWidth);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		textureX = texWidth - textureX - 1;
	step = 1.0 * texHeight / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end) 
	{
		textureY = (int)tex_pos & (texHeight - 1);
		tex_pos += step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		y++;
	}
}
