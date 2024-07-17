/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:38:03 by darismen          #+#    #+#             */
/*   Updated: 2024/07/15 12:03:13 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	int		x;
	int		y;
}	t_vec;

typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

#endif