/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:09:25 by darismen          #+#    #+#             */
/*   Updated: 2024/07/17 10:10:14 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_line
{
	int	x; //the x coordinate of line relative to screen
	int	y; //the current pixel index of the line (along y axis)
	int	y0; //y start index of drawing texture
	int	y1; //y end index of drawing texture
	int	tex_x; //x coordinate of texture to draw
	int	tex_y; //y coordinate of texture to draw
}	t_line;

