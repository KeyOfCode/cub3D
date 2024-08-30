/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:40:21 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:15:07 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ' && map[row][i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_map_spaces(char **map, int width)
{
	char	*line;
	int		i;

	i = -1;
	while (map[++i])
	{
		line = ft_calloc(width + 1, sizeof(char *));
		line = ft_memset(line, ' ', width);
		line = ft_memcpy(line, map[i], ft_strlen(map[i]));
		free(map[i]);
		map[i] = line;
	}
}

int	check_sides(char **map, int i, int j)
{
	if (map[i][j + 1] && map[i][j + 1] == ' ')
		return (0);
	if (map[i][j - 1] && map[i][j - 1] == ' ')
		return (0);
	if (map[i + 1][j] && map[i + 1][j] == ' ')
		return (0);
	if (map[i - 1][j] && map[i - 1][j] == ' ')
		return (0);
	return (1);
}

int	is_enclosed(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	ft_fill_map_spaces(game->map, game->max_width);
	map = game->map;
	i = -1;
	if (!check_wall(map, 0, 0))
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '0')
				if (check_sides(map, i, j) == 0)
					return (0);
	}
	if (!check_wall(map, i - 1, 0))
		return (0);
	return (1);
}
