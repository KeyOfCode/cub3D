/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:19:18 by darismen          #+#    #+#             */
/*   Updated: 2024/07/17 13:56:34 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (sub[0] == '\0')
		return ((char *)str);
	while (str[h] != '\0')
	{
		n = 0;
		while (str[h + n] == sub[n] && (h + n) < len)
		{
			if (str[h + n] == '\0' && sub[n] == '\0')
				return ((char *)&str[h]);
			n++;
		}
		if (sub[n] == '\0')
			return ((char *)&str[h]);
		h++;
	}
	return (0);
}
