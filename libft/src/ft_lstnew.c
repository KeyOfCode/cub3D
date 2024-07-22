/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:23 by darismen          #+#    #+#             */
/*   Updated: 2024/07/18 11:47:01 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* Description 
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL. */
t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!(newlist))
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
