#include <cub3d.h>

mlx_texture_t	*set_texture(t_texture *textures, int symb)
{
	t_texture	*head;

	head = textures;
	while (head)
	{
		if (head->symbol == symb)
			return (*head->sprites);
		head = head->next;
	}
	return (ft_cub_error(5), NULL);
}

static void	ft_get_texture(t_ray *ray, t_game *game)
{
	t_texture	*textures;

	textures = game->textures;
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			ray->texture = set_texture(textures, WE);
		else
			ray->texture = set_texture(textures, EA);
	}
	else
	{
		if (ray->dir.y > 0)
			ray->texture = set_texture(textures, SO);
		else
			ray->texture = set_texture(textures, NO);
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
/* 	printf("intial pos:%f step:%f\n",to_rend.pos, to_rend.step); */
	y = ray->draw_start;
/* 	printf("draw-start: %d draw_end: %d\n", ray->draw_start, ray->draw_end); */
	while (y < ray->draw_end)
	{
		to_rend.y = (int)to_rend.pos % TEX_HEIGHT;
		to_rend.pos += to_rend.step;
/* 		printf("x: %d y: %d\n", to_rend.x, to_rend.y); */
		color = ft_get_color(ray->texture, to_rend.x, to_rend.y);
		if (color > 0)
			pixel_data[y][x] = color;
		y++;
	}
}
