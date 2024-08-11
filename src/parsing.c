/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:53:35 by darismen          #+#    #+#             */
/*   Updated: 2024/08/11 09:38:05 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_map(char *relative_path, t_game *game)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(&relative_path[path_len - 4], ".cub", 4) != 0)
		return (0);
	game->map_fd = open(relative_path, O_RDONLY);
	if (game->map_fd < 0)
		return (0);
	// ft_printf_fd(2, "game->map_fd: %d\n", game->map_fd);
	return (1);
}

int	init_texture_lst(t_game *game)
{
	t_texture	*head;
	char		*line;
	int			i;
	int			j;
	int			stop;

	line = "";
	head = game->textures;
	j = -1;
	while (++j < IMG_COUNT)
	{
		ft_printf_fd(2, "texture_lst\n");
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
		// ft_printf_fd(2, "Line: %s", line);
		// ft_printf_fd(2, "head: %p\n", head);
		// ft_printf_fd(2, "line[0]: %c\n", line[0]);
		// ft_printf_fd(2, "\tname: %s\n", head->name);
		// ft_printf_fd(2, "\tpath: %s\n\n", head->path);
		head = head->next;
		free(line);
	}
	return (1);
}

int	parser(t_game *game)
{
	int	i;

	fill_lst(game);
	i = -1;
	while (++i < IMG_COUNT)
		init_texture_lst();
	while ()
}

// ft_error("Init Texture lst");
		// ft_printf_fd(2, "Textures game->map_fd: %d\n", game->map_fd);
		// ft_printf_fd(2, "Line: %s\n", line);
		// ft_printf_fd(2, "head: %p\n", head);
		// ft_printf_fd(2, "line[0]: %c\n", line[0]);
		// ft_printf_fd(2, "\tname: %s\n", head->name);
		// ft_printf_fd(2, "\tpath: %s\n\n", head->path);

int	max_width(int width)
{
	static int	old = -1;

	if (width < old)
		width = old;
	old = width;
	return (width);
}

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
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
		if (game->lst_map == NULL)
			game->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&(game->lst_map), ft_lstnew(line));
	}
	if (line)
		free(line);
	return (1);
}

		// ft_printf_fd(2, "fill_lst\n");
		// ft_printf_fd(2, "line: %s", line);
			// ft_printf_fd(2, "exit!\n\n");
		// ft_printf_fd(2, "fill_lst Complete!\n\n");

int	convert_lst(t_game *game)
{
	t_list	*lst;
	int		i;

	game->g_height = ft_lstsize(game->lst_map);
	if (game->g_height < 3)
		return (0);
	game->map = ft_calloc(game->g_height + 1, sizeof(char *));
	if (!game->map)
		exit(EXIT_FAILURE);
	lst = game->lst_map;
	i = 0;
	while (lst)
	{
		game->map[i] = ft_chrrmv(lst->content, '\n');
		if (!game->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	return (1);
}
