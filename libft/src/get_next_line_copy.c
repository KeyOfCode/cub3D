/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:28:52 by darismen          #+#    #+#             */
/*   Updated: 2024/07/23 13:07:52 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char	*pointer)
{
	free(pointer);
	pointer = NULL;
	return (NULL);
}

int	ft_strcontains(char *s, int c)
{
	int	index;

	index = 0;
	if (!s || *s == 0)
		return (0);
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strjoin_alt(char *s1, char *s2, int length)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	while (s1 && s1[i] && i < (length - 1))
	{
		result[i] = s1[i];
		i++;
	}
	while (i < (length - 1) && s2 && s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_stj_f(char **to_free, char *buf, int length)
{
	char	*new;

	new = ft_strjoin_alt(*to_free, buf, length);
	if (!new)
	{
		ft_clean(*to_free);
		return (NULL);
	}
	ft_clean(*to_free);
	return (new);
}

static char	*ft_fill_buffer(int fd, char **save)
{
	char	*buf;
	int		bytes_read;

	bytes_read = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (!ft_strcontains(*save, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == BUFFER_SIZE)
			*save = ft_stj_f(save, buf, ft_strlen(*save) + ft_strlen(buf) + 1);
		else
			*save = ft_stj_f(save, buf, ft_strlen(*save) + bytes_read + 1);
		if (!*save)
		{
			ft_clean(buf);
			return (ft_clean(*save));
		}
	}
	if (bytes_read < 0)
		return (ft_clean(*save), ft_clean(buf));
	free(buf);
	return (*save);
}

static char	*ft_clean_buffer(char *save)
{
	char	*aux;
	int		length;
	char	*new_save;

	new_save = NULL;
	length = 0;
	aux = ft_strchr(save, '\n');
	if (aux)
	{
		length = ft_strlen(aux + 1);
		new_save = ft_strjoin_alt(aux + 1, new_save, length + 1);
		if (!new_save)
			return (ft_clean(save));
		free(save);
		return (new_save);
	}
	return (ft_clean(save));
}

char	*ft_extract_line(char **save, char *line)
{
	char	*aux;

	aux = ft_strchr(*save, '\n');
	if (ft_strcontains(*save, '\n'))
	{
		if (aux != *save)
			line = ft_strjoin_alt(*save, line, ((aux - *save) + 1 + 1));
		else
			line = ft_strjoin_alt(*save, line, 1 + 1);
	}
	else
		line = ft_strjoin_alt(*save, line, ft_strlen(*save) + 1);
	if (!line)
		return (NULL);
	*save = ft_clean_buffer(*save);
	if (!save)
		return (ft_clean(*save));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_fill_buffer(fd, &save[fd]);
	if (!save[fd])
		return (ft_clean(save[fd]));
	line = ft_extract_line(&save[fd], line);
	if (!line)
	{
		ft_clean(line);
		return (ft_clean(save[fd]));
	}
	if (*line == '\0')
		return (ft_clean(line));
	else
		return (line);
}
