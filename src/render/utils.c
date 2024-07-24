#include <cub3D.h>

void	ft_init_vector(t_vec2d *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	ft_init_dirs(t_game *game)
{
	if (game->yaw == 0)
	{
		ft_initvector(&(game->player.dir), -1, 0);
		ft_initvector(&(game->player.fov), 0, -0.66);
	}
	else if (game->yaw == 90)
	{
		ft_initvector(&(game->player.dir), 0, -1);
		ft_initvector(&(game->player.fov), 0.66, 0);
	}
	else if (game->yaw == 180)
	{
		ft_initvector(&(game->player.dir), 1, 0);
		ft_initvector(&(game->player.fov), 0, 0.66);
	}
	else if (game->yaw == 270)
	{
		ft_initvector(&(game->player.dir), 0, 1);
		ft_initvector(&(game->player.fov), -0.66, 0);
	}
}
