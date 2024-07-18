#include <cub3d.h>

/**
 * Información necesaria:
 * t_game->t_player
 * -Posición del jugador t_game->t_player->post
 * -Dirección del jugador t_game->t_player->dir
 * -Vector plano de la cámara t_game->t_player->fov
 * -Asumimos que FOV = 60º
 */

int ft_init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir.x = player->dir.x + player->fov.x * ray->camera_x;
	ray->dir.y = player->dir.y + player->fov.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->deltadist.x = fabs(1 / ray->dir.x);
	ray->deltadist.y = fabs(1 / ray->dir.y);
}

static void ft_set_step_directions(t_ray *ray, t_player *player)
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

      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
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
		else if (data->map[ray->map.y][ray->map.x] > '0')
			hit = 1;
	}
}

int ft_raycast(t_game *game)
{
	t_ray ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < WIN_WIDTH)
	{
		ft_init_ray(&ray, game->player, x);
		ft_set_step_directions(&ray, game->player);
		ft_dda()
		x++;
	}
}