/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:19:31 by darismen          #+#    #+#             */
/*   Updated: 2024/07/23 13:15:39 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>

/* char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = -1;
	j = 0;
	if (newstr && s1)
	{
		while (s1[++i])
			newstr[i] = s1[i];
	}
	while (newstr && s2[j])
		newstr[i++] = s2[j++];
	return (newstr);
} */

size_t	ft_priv_strlen(const char *s)
{
	size_t	l;

	l = 0;
	if (s == NULL)
		return (0);
	while (s[l] != 0)
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len1;
	int		tot_len;
	int		i;
	int		j;

	len1 = ft_priv_strlen(s1);
	tot_len = len1 + ft_priv_strlen(s2);
	newstr = (char *)ft_calloc(tot_len + 1, sizeof(char));
	i = -1;
	j = 0;
	if (newstr && s1)
	{
		while (s1[++i])
			newstr[i] = s1[i];
	}
	while (newstr[i] && s2[j])
		newstr[i++] = s2[j++];
	return (newstr);
}

char	*ft_join_free(char *s1, char *s2, int f)
{
	char	*aux;

	aux = ft_strjoin(s1, s2);
	if (f >= 1)
		free(s1);
	if (f >= 2)
		free(s2);
	return (aux);
}

/* char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		tot_len;
	int		i;
	char	*newstr;

	len1 = ft_priv_strlen(s1);
	tot_len = len1 + ft_priv_strlen(s2);
	newstr = (char *)ft_calloc(tot_len + 1, sizeof(char));
	if (!(newstr))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (len1 + i < tot_len)
	{
		newstr[len1 + i] = s2[i];
		i++;
	}
	return (newstr);
} */

	// newstr = (char *)malloc(tot_len + 1);