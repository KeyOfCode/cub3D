/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:38:03 by darismen          #+#    #+#             */
/*   Updated: 2024/08/20 10:25:26 by darismen         ###   ########.fr       */
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
	double	modulo;
}	t_vec2d;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
	double	modulo;
}	t_vec3d;

#endif