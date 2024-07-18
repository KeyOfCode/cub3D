/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:10:57 by darismen          #+#    #+#             */
/*   Updated: 2024/07/18 17:26:10 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <math.h>

# include "vector.h"

# define WIDTH 1280
# define HEIGHT 720

typedef enum s_sprites
{
	SPRITES,
	PLAYER = 1,
	GATE,
	COIN,
	OTHER,
	IMG_COUNT
}	t_sprites;

/// @brief Structure for the player
/**
 * @param pos : position relative to the map.
 * @param direction : (0 left, 1 right)
*/
typedef struct s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		fov;
	t_vec3d		cam;
	double		yaw;
	double		pitch;
	int			hp;
}	t_player;

/// @brief Struct that contains all the data of the game
/*!
 * @struct t_game
 * @param mlx : mlx pointer
 * @param img : MLX42 img ppointer, contains each sprite.
 * @param gw 	: game width (number of horizontal tiles)
 * @param gh 	: game height (number of vertical tiles)
 * @param fd 	: file descriptor
 * @param map_fd 	: map file descriptor
 * @param lst_map : *linked list that contains datas map
 * @param map : **map (2D array)
 * @param ps 	: *player sprite
 * @param gs 	: *gate sprite
 * @param ms 	: *monster sprite
 * @param cs 	: *collectable sprite
 * @param os 	: *other sprite
 * @param nc 	: number collectable
 * @param nm 	: number movements
 * @param player 	: *player struct
*/
typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img[IMG_COUNT];
	int					gw;
	int					gh;
	int					fd;
	int					map_fd;
	t_list				*lst_map;
	char				**map;
	mlx_texture_t		*ps[4];
	mlx_texture_t		*gs[2];
	mlx_texture_t		*os[4];
	int					nc;
	int					nm;
	t_player			*player;
	t_ray				ray;
}	t_game;

typedef enum move
{
	X,
	Y,
	xy
}	t_move;


typedef struct s_ray
{
	double	camera_x;
	t_vec2d dir;
	t_vec2d map;
	t_vec2d step;
	t_vec2d sidedist;
	t_vec2d deltadist;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;


void	hooks(mlx_key_data_t keydata, void *param);

void	ft_error(int type);

/* Init */

void	init_game(char **argv, t_game *game);
int		init_map(int argc, char *argv[], t_game *game);
int		init_player(t_game *game);
void	init_sprites(t_game *game);
int		find_player_pos(t_game *game);

/* Draw */

void	draw_block(int x, int y, mlx_texture_t *sprite, t_game *game);
void	erase_block(t_game *game, mlx_texture_t *sprite);
void	draw_background(t_game *game);
void	draw_player(t_game *game);
int		change_player_dir(t_game *game, char dir);
void	draw_other(t_game *game);

/* Hooks */

void	hook_register(t_game *game);
void	exit_game(t_game *game);

/* Parsing */

int		open_map(char *relative_path, t_game *game);
int		fill_lst(t_game *game);
int		convert_lst(t_game *game);
int		size_check(t_game *game);
int		allowed_char(t_game *game);
int		sides_is_wall(t_game *game);
int		required_char(t_game *game);
int		path_to_exit(t_game *game);

/* Player */
int		movement(t_game *game, int *pos, char dir);
void	movecounter(t_game *game);
int		collision(t_game *game, int pos[2], char dir);
void	coin_collision(t_game *game, int pos[2]);
void	gate_collision(t_game *game, int *pos);

/* Utils */
void	fps(t_game *game);
void	resize_map(t_game *game);
int		ft_2darr_len(void **arr);
void	ft_2darrfree(void **arr);

#endif