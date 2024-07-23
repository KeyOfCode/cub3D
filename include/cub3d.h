/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:10:57 by darismen          #+#    #+#             */
/*   Updated: 2024/07/23 13:01:42 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <signal.h>
// # include <sys/stat.h>
# include <sys/time.h>
# include <features.h>
# define __USE_MISC 1
# include <math.h>

# include "vector.h"

# define WIDTH 		1280
# define HEIGHT 	720
# define FOV		60
# define ROT_SPD	0.045
# define SPEED		10.0
# define LERP		0.2
# define SYMBOLS	"01NSEW "

# define BPX 64

typedef enum move
{
	X,
	Y,
	xy
}	t_move;

typedef enum s_sprites
{
	NO = 0,
	SO,
	EA,
	WE,
	FLOOR,
	CEIL,
	IMG_COUNT
}	t_sprites;

typedef enum dirs
{
	DOWN,
	RIGHT,
	UP,
	LEFT
}	t_dirs;

/** @brief Structure for texture list
 * @param name 		: texture name.
 * @param path 		: texture path.
 * @param symbol 	: texture symbol in map.
 * @param size	 	: pixel size.
 * @param nb		: number of stored sprites. Min 1.
 * @param type		: texture enum t_sprites code.
 * @param sprites 	: stored mlx_textures. Can store animated sprites.
 * @param next		: pointer to next texture. (Could be removed).
 */
typedef struct s_texture
{
	char				*name;
	char				*path;
	char				symbol;
	int					size;
	int					nb;
	int					type;
	mlx_texture_t		**sprites;
	struct s_texture	*next;
}	t_texture;

/** @brief Structure for the player
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
	t_vec3d		speed;
	double		rot_spd;
}	t_player;

/// @brief Struct that contains all the data of the game
/*!
 * @struct t_game
 * @param mlx 		: mlx pointer
 * @param img 		: MLX42 img ppointer, contains each sprite.
 * @param max_width	: game width (number of horizontal tiles)
 * @param g_height 	: game height (number of vertical tiles)
 * @param fd 		: file descriptor
 * @param map_fd 	: map file descriptor
 * @param lst_map 	: *linked list that contains datas map
 * @param map 		: **map (2D array)
 * @param nb_textures	: number of textures.
 * @param textures 	: texture struct pointer
 * @param player 	: *player struct pointer
 * @param ply_pos[2]	: player global position
*/
typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img[IMG_COUNT];
	int					*buff_tex[IMG_COUNT];
	char				**map_buff;
	int					max_width;
	int					g_height;
	int					fd;
	int					map_fd;
	t_list				*lst_map;
	char				**map;
	int					nb_textures;
	t_texture			*textures;
	t_player			*player;
	int					ply_pos[2];
}	t_game;



// typedef enum s_others
// {
// 	bg1,
// 	bg2,
// 	wall1,
// 	wall2
// }	t_others;

void	hooks(mlx_key_data_t keydata, void *param);

void	ft_cub_error(int type);

/* Init */

void	init_game(t_game *game);
int		init_map(int argc, char *argv[], t_game *game);
int init_texture_lst(t_game *game);
void	init_player(t_player *player);
void	init_sprites(t_game *game);
int		find_player_pos(t_game *game);

/* Textures */
char	*path_to_sprite(char *sprite_name, int nb);


/* Draw */

void	draw_block(int x, int y, int type, t_game *game);
void	erase_block(t_game *game, mlx_texture_t *sprite);
void	draw_walls(t_game *game);
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
int		is_enclosed(t_game *game);
int		allowed_char(t_game *game);
int		sides_is_wall(t_game *game);
int		required_char(t_game *game);
int		path_to_exit(t_game *game);

/* Player */
int		movement(t_game *game, t_player *player, int sign, char cross);
void	rotation(t_player *player, int dir);
void	ft_player_init_pos(t_player *player, char dir,
			int x, int y);
// void	collision(t_game *game, t_player *player);

/* Utils */
// void	fps(t_game *game);
void	resize_map(t_game *game);
int		ft_2darr_len(void **arr);
void	ft_2darrfree(void **arr);
float	to_rad(float degree);
float	lerp(float a, float b, float f);
void	skip_spaces(char *str, int *i);

#endif