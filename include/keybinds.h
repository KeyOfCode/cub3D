/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:05:00 by darismen          #+#    #+#             */
/*   Updated: 2024/08/25 12:24:25 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBINDS_H
# define KEYBINDS_H

# include "stdbool.h"

# define TRUE 1
# define FALSE 0

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	c;
	bool	right_arrow;
	bool	left_arrow;
	bool	shift;
	int		mouse_x;
	int		prev_mouse_x;
	int		mouse_y;
	int		prev_mouse_y;
}	t_keys;

#endif