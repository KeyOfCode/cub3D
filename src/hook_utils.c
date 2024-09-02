/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:54:54 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 12:04:59 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (lst->sprites && lst->sprites[0])
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
		if (game->img)
			mlx_delete_image(game->mlx, game->img);
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
