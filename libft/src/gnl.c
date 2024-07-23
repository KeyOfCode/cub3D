/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:28:52 by darismen          #+#    #+#             */
/*   Updated: 2024/07/23 12:35:40 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	bytes = read(fd, &character, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

/* char	*get_next_line(int fd)
{
	int		index = 0;
	int		bytes;
	char	character;
	char	*buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes = read(fd, &character, 1)) > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
} */


