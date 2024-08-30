/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:53:35 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:46:20 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_lst(t_game *game)
{
	char	*line;
	int		count;

	line = "";
	count = 0;
	while (line)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL && game->lst_map != NULL)
			return (1);
		game->max_width = max_width((int)ft_strlen(line) - 1);
		if (game->max_width < 4)
			return (free(line), 0);
		if ((line[0] == '1' || line[0] == ' ') && count < 6)
			return (free(line), 0);
		ft_lstadd_back(&(game->lst_map), ft_lstnew(line));
		count++;
	}
	return (1);
}

int	store_texture(t_game *game, t_list *lst)
{
	t_texture	*head;
	char		*line;
	int			i;
	int			stop;

	head = ft_calloc(sizeof(t_texture), 1);
	if (!head)
		return (0);
	line = lst->content;
	i = -1;
	while (line[++i] != ' ')
		;
	head->name = ft_substr(line, 0, i);
	stop = i + 1;
	while (line[++i] != '\n')
		;
	head->path = ft_substr(line, stop, i - 3);
	if (!head->name || !head->path)
		return (ft_texture_free(head), 0);
	ft_texture_addback(&game->textures, head);
	return (1);
}

int	store_color(int color[4], t_list *lst)
{
	int		i;
	char	**values;
	char	*start;

	i = -1;
	start = ft_strchr(lst->content, ' ');
	values = ft_split(start, ',');
	while (++i < 4)
	{
		if (values[i])
			color[i] = ft_atoi(values[i]);
		if (!color[i])
			color[i] = 0;
	}
	ft_2darrfree((void **)values);
	return (1);
}

int	store_map(t_game *game, t_list *lst)
{
	int		i;

	game->g_height = ft_lstsize(lst);
	if (game->g_height < 3)
		return (0);
	game->map = ft_calloc(game->g_height + 1, sizeof(char *));
	if (!game->map)
		return (0);
	i = 0;
	while (lst)
	{
		game->map[i] = ft_chrrmv(lst->content, '\n');
		game->map[i][ft_strlen(lst->content) - 1] = '\0';
		if (!game->map[i])
			return (0);
		i++;
		lst = lst->next;
	}
	return (1);
}

int	parser(t_game *game)
{
	int		i;
	t_list	*lst;

	if (!fill_lst(game))
		return (0);
	lst = game->lst_map;
	i = -1;
	while (++i < IMG_COUNT)
	{
		if (!store_texture(game, lst))
			return (0);
		lst = lst->next;
	}
	store_color(game->floor, lst);
	lst = lst->next;
	store_color(game->ceiling, lst);
	lst = lst->next;
	if (!store_map(game, lst))
		return (0);
	return (1);
}
