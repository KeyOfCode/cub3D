#include <cub3d.h>

static void	ft_get_texture(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
		{
			printf("W\n");
			ray->texture = game->textures[0]; //WEST0
		}
		else
		{
			printf("E\n");
			ray->texture = game->textures[0]; //EAST2
		}
	}
	else
	{
		if (ray->dir.y > 0)
		{
/* 			printf("S\n"); */
			ray->texture = game->textures[0]; //SOUTH3
		}
		else
		{
			printf("N\n");
			ray->texture = game->textures[0]; //NORTH1
		}
	}
}

void	ft_register_pixels(t_ray *ray, t_game *game, int **pixel_data, int x)
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
	/* printf("draw-start: %d draw_end: %d\n", ray->draw_start, ray->draw_end); */
	while (y < ray->draw_end) 
	{
		to_rend.y = (int)to_rend.pos & (TEX_HEIGHT - 1);
		to_rend.pos += to_rend.step;
		color = ft_get_color(ray->texture, to_rend.x, to_rend.y);
/* 		if (ray->side == 1) 
			color = (color >> 1) & 8355711; */
		if (color > 0)
		{
 			pixel_data[y][x] = color;
		}
		y++;
	}
}
