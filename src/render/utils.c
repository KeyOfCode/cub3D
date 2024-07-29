#include <cub3d.h>

void	ft_init_vector(t_vec2d *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	ft_init_dirs(t_game *game)
{
/* 	printf("%f\n", game->player->yaw); */
	if (game->player->yaw == 0)
	{
		ft_init_vector(&(game->player->dir), -1, 0);
		ft_init_vector(&(game->player->fov), 0, -0.66);
	}
	else if (game->player->yaw == 90)
	{
		ft_init_vector(&(game->player->dir), 0, -1);
		ft_init_vector(&(game->player->fov), 0.66, 0);
	}
	else if (game->player->yaw == 180)
	{
		ft_init_vector(&(game->player->dir), 1, 0);
		ft_init_vector(&(game->player->fov), 0, 0.66);
	}
	else if (game->player->yaw == 270)
	{
		/* printf("player dir %f %f\n", game->player->dir.x, game->player->dir.y); */
		ft_init_vector(&(game->player->dir), 0, 1);
/* 		printf("player dir %f %f\n", game->player->dir.x, game->player->dir.y); */
		ft_init_vector(&(game->player->fov), -0.66, 0);
	}
}
