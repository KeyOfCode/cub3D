/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:20:05 by darismen          #+#    #+#             */
/*   Updated: 2024/07/23 11:54:30 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd);

void	ft_error(char const *s)
{
	ft_putendl_fd(s, 2);
}

/* Descripción 
	Envía la string ’s’ al file descriptor dado,
	seguido de un salto de línea. */
void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
