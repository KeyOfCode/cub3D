#include <cub3d.h>

void	ft_init_dirs(t_game *game)
{
/* 	printf("%f\n", game->player->yaw); */
	if (game->player->yaw == 0)
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
		game->player->fov.x = 0;
		game->player->fov.y = -0.66;
	}
	else if (game->player->yaw == 90)
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
		game->player->fov.x = 0.66;
		game->player->fov.y = 0;
	}
	else if (game->player->yaw == 180)
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
		game->player->fov.x = 0;
		game->player->fov.y = 0.66;
	}
	else if (game->player->yaw == 270)
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
		game->player->fov.x = -0.66;
		game->player->fov.y = 0;
	}
}
