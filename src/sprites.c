/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:36:17 by darismen          #+#    #+#             */
/*   Updated: 2024/09/02 12:12:07 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*path_to_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("./textures/wall/", sprite_name);
	str2 = ft_strjoin(str1, "_");
	free(str1);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".png");
	free(str1);
	free(nbr);
	return (str2);
}

/**
* @param	nb_sprite : it points to each frame of their animations.
* @param	fd : checks if the sprite exists.
*/
void	load_textures(int nb_sprite, t_texture *textures, t_game *game)
{
	static int	type = -1;
	int			index;
	int			fd;

	index = -1;
	textures->sprites = ft_calloc(nb_sprite, sizeof(mlx_texture_t *));
	while (++index < nb_sprite)
	{
		fd = open(textures->path, O_RDONLY);
		if (fd < 0)
			ft_cub_error("texture failed to load", game);
		close(fd);
		textures->sprites[index] = mlx_load_png(textures->path);
	}
	textures->type = ++type;
}

void	init_sprites(t_game *game)
{
	t_texture	*head;

	head = game->textures;
	while (head)
	{
		load_textures(1, head, game);
		head = head->next;
	}
}

/* char	*path_to_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("./textures/wall/", sprite_name);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, "_");
	free(str1);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".png");
	free(str1);
	free(nbr);
	return (str2);
} */