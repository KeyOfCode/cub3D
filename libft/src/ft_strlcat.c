/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:47:30 by darismen          #+#    #+#             */
/*   Updated: 2024/08/15 13:25:05 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;

	i = 0;
	j = 0;
	length = ft_strlen(dest);
	if (size <= length)
		return (size + ft_strlen(src));
	length = ft_strlen(dest) + ft_strlen(src);
	while (dest[i])
	{
		i++;
	}
	while (src[j] && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length);
}

// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	res;

// 	i = 0;
// 	while (dest[i] != '\0')
// 		i++;
// 	res = 0;
// 	while (src[res] != '\0')
// 		res++;
// 	if (size <= i)
// 	{
// 		res += size;
// 	}
// 	else
// 		res += i;
// 	j = 0;
// 	while (src[j] != '\0' && i + 1 < size)
// 	{
// 		dest[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	return (res);
// }
