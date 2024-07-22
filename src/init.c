/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:53:40 by darismen          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:09 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(char **argv, t_game *game)
{
	(void)argv;
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		ft_error(5);
	game->gw = -1;
	game->gh = -1;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->img[0] = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->nm = 0;
	game->lst_map = NULL;
}

int	init_map(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
		ft_error(1);
	if (!open_map(argv[1], game))
		ft_error(2);
	if (!fill_lst(game))
		ft_error(3);
	if (!convert_lst(game))
		ft_error(3);
	if (!size_check(game))
		ft_error(3);
	if (!allowed_char(game))
		ft_error(3);
	if (!sides_is_wall(game))
		ft_error(3);
	if (!required_char(game))
		ft_error(3);
	if (!path_to_exit(game))
		ft_error(3);
	return (1);
}

int	find_player_pos(t_game *game)
{
	char	*dir;
	int		i;
	int		j;

	dir = ft_strdup ("NSWE");
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr(dir, game->map[i][j]))
			{
				game->player->pos.x = (double)j;
				game->player->pos.y = (double)i;
				ft_set_player_dir(game, game->map[i][j]);
				return (free (dir), 1);
			}
		}
	}
	return (free (dir), 0);
}
