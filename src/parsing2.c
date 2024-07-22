/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:49:44 by darismen          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:04 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Checks the allowed characters
int	allowed_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (ft_strchr("01NSEW ", game->map[i][j]) == 0
				|| !(j == (int)ft_strlen(game->map[i]) - 1
				&& game->map[i][j] == '\n'))
				return (0);
	}
	return (1);
}

int	check_wall(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_enclosed(t_game *game)
{
	char	**map;
	char	**split;
	int		i;
	int		j;

	map = game->map;
	i = -1;
	if (!check_wall(map, 0, 0))
		return (0);
	while (map[++i])
	{
		split = ft_split(map[i], ' ');
		j = -1;
		while (split[++j])
			if (split[j][0] != 1 &&
				split[j][ft_strlen(split[j])] != 1)
				return (free(split), 0);
	}
	free(split);
	if (!check_wall(map, i, 0))
		return (0);
	return (1);
}

int	required_char(t_game *game)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	check = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (ft_strchr("NSWE", game->map[i][j]))
				if (++check == 1)
					ft_player_init_pos(game->player,
						game->map[i][j], j, i);
	}
	if (check != 1)
		return (0);
	return (1);
}

/** @brief Make a copy of the game->map
 * 
 * 
 * @param map game->map
 * @return char** 
 */
char	**ft_map_copy(char **map)
{
	char	**copy;
	int		i;

	copy = ft_calloc(ft_2darr_len((void **)map) + 1, sizeof(char *));
	if (!copy)
		return (0);
	i = -1;
	while (map[++i])
		copy[i] = ft_strdup(map[i]);
	return (copy);
}
