/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:43:56 by darismen          #+#    #+#             */
/*   Updated: 2024/08/12 14:02:16 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_texture_addback(t_texture **lst, t_texture *new)
{
	t_texture	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	ft_texture_free(t_texture *texture)
{
	// int	i;

	if (texture->name)
		free (texture->name);
	if (texture->path)
		free (texture->path);
	// i = -1;
	// while (texture->sprites[++i])
	// 	mlx_delete_texture(texture->sprites[i]);
	free (texture);
	texture = NULL;
}
