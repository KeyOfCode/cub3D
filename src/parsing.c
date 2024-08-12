/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:53:35 by darismen          #+#    #+#             */
/*   Updated: 2024/08/12 15:29:39 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_width(int width)
{
	static int	old = -1;

	if (width < old)
		width = old;
	old = width;
	return (width);
}

int	fill_lst(t_game *game)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL && game->lst_map != NULL)
			return (1);
		game->max_width = max_width((int)ft_strlen(line) - 1);
		if (game->max_width < 4)
			return (0);
		ft_lstadd_back(&(game->lst_map), ft_lstnew(line));
	}
	if (line)
		free(line);
	return (1);
}

/* int	init_texture_lst(t_game *game)
{
	t_texture	*head;
	char		*line;
	int			i;
	int			j;
	int			stop;

	line = "";
	j = -1;
	while (++j < IMG_COUNT)
	{
		head = ft_calloc(sizeof(t_texture), 1);
		line = get_next_line(game->map_fd);
		i = -1;
		while (line[++i] != ' ')
			head->name = ft_substr(line, 0, i + 1);
		stop = i + 1;
		while (line[++i] != '\n')
			head->path = ft_substr(line, stop, i);
		if (!head)
			return (0);
		ft_texture_addback(&(game->textures), head);
		free(head);
		free(line);
	}
	return (1);
} */

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
	head->path = ft_substr(line, stop, i);
	if (!head->name || !head->path)
		return (ft_texture_free(head), 0);
	// ft_printf_fd(2, "\tname: %s\n", head->name);
	// ft_printf_fd(2, "\tpath: %s\n\n", head->path);
	ft_texture_addback(&game->textures, head);
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
		if (!game->map[i])
			return (0);
		i++;
		lst = lst->next;
	}
	return (1);
}

		// ft_printf_fd(2, "[%d]: %s\n", i, game->map[i]);

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
	if (!store_map(game, lst))
		return (0);
	return (1);
}

// ft_error("Init Texture lst");
		// ft_printf_fd(2, "Textures game->map_fd: %d\n", game->map_fd);
		// ft_printf_fd(2, "Line: %s\n", line);
		// ft_printf_fd(2, "head: %p\n", head);
		// ft_printf_fd(2, "line[0]: %c\n", line[0]);
		// ft_printf_fd(2, "\tname: %s\n", head->name);
		// ft_printf_fd(2, "\tpath: %s\n\n", head->path);

/* void	free_str(char **str)
{
	free(*str);
	*str = NULL;
} */