/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:03:23 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 12:03:40 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_get_color(mlx_texture_t *texture, int pos_x, int pos_y)
{
	uint32_t	color;
	int			pos;

	pos = (pos_y * TEX_WIDTH + pos_x) * 4;
	color = get_rgba(texture->pixels[pos],
			texture->pixels[pos + 1],
			texture->pixels[pos + 2],
			texture->pixels[pos + 3]);
	return (color);
}
