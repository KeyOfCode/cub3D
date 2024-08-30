/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:54:54 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:42:42 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stop_player(t_player *player)
{
	player->speed = 0.0;
}

void	press_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == (MLX_KEY_ESCAPE))
		exit_game(game);
	if (keydata.key == MLX_KEY_W)
		game->keys.w = TRUE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = TRUE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = TRUE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = TRUE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right_arrow = TRUE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left_arrow = TRUE;
}

void	release_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W)
		game->keys.w = FALSE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = FALSE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = FALSE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = FALSE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right_arrow = FALSE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left_arrow = FALSE;
	stop_player(game->player);
}

void	ft_free_texture_lst(t_texture *lst)
{
	t_texture	*current;

	if (!lst)
		return ;
	while (lst)
	{
		current = (lst)->next;
		free(lst->name);
		free(lst->path);
		if (lst->sprites)
			mlx_delete_texture(lst->sprites[0]);
		free(lst->sprites);
		free(lst);
		lst = current;
	}
	lst = 0;
}

void	exit_game(t_game *game)
{
	if (game)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		if (game->map)
			ft_2darrfree((void **)game->map);
		if (game->lst_map)
			ft_lstclear(&game->lst_map, free);
		if (game->textures)
			ft_free_texture_lst(game->textures);
		if (game->player)
			free(game->player);
		free(game);
	}
	ft_printf_fd(1, "\nGame Ended succesfully\n");
	exit(EXIT_SUCCESS);
}
