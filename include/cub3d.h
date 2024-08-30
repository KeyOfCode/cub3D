/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:10:57 by darismen          #+#    #+#             */
/*   Updated: 2024/08/30 13:35:54 by darismen         ###   ########.fr       */
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
# include <sys/time.h>
# include <features.h>
# define __USE_MISC 1
# include <math.h>

# include "vector.h"
# include "keybinds.h"

# define WIDTH 		1280
# define HEIGHT 	720
# define FOV		60
# define ROT_SPD	5
# define SPEED		5
# define TOLERANCE	.5
# define LERP		0.2
# define SYMBOLS	"01NSEW "
# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define TEX_SIZE	64

# define BPX 64

typedef enum s_sprites
{
	NO = 0,
	SO,
	EA,
	WE,
	IMG_COUNT
}	t_sprites;

/** @brief Structure for texture list
 * @param name 		: texture name.
 * @param path 		: texture path.
 * @param symbol 	: texture symbol in map.
 * @param type		: texture enum t_sprites code.
 * @param size	 	: pixel size.
 * @param nb		: number of stored sprites. Min 1.
 * @param sprites 	: stored mlx_textures. Can store animated sprites.
 * @param next		: pointer to next texture. (Could be removed).
 */
typedef struct s_texture
{
	char				*name;
	char				*path;
	int					type;
	mlx_texture_t		**sprites;
	struct s_texture	*next;
}	t_texture;

struct	s_game;

/** @brief Structure for the player
 * @param pos : position relative to the map.
 * @param direction : (0 left, 1 right)
*/
typedef struct s_player
{
	t_vec2d				pos;
	t_vec2d				dir;
	t_vec2d				perp;
	t_vec2d				fov;
	t_vec3d				cam;
	double				yaw;
	double				speed;
	double				rot_spd;
}	t_player;

/**
 * @brief Structure for raycast
 * @param camera_x 		: X coordinate of the camera plane.
 * @param dir 			: Direction vector of the ray.
 * @param map 			: Current coordinates on the map, represents a cell.
 * @param step	 		: Steps in both X and Y to perform DDA, 1 or -1.
 * @param sidedist		: Distance from player to the collision wall.
 * @param deltadist		: Distance from 1 point of 
 * 	the grid to the closest grid line, X or Y.
 * @param wall_dist 	: Perpendicular distance from 
 * 	player to the collision point.
 * @param wall_x		: Exact point of where the wall was hit.
 * @param side	 		: Indicates if the ray 
 * 	has hit a Y grid line or an X grid line.
 * @param line_height	: Distance from player to the collision wall.
 * @param draw_start	: Indicates where in the 
 * 	screen a wall should start to be drawn.
 * @param draw_end 		: Indicates where in the screen a wall should end.
 */
typedef struct s_ray
{
	double			camera_x;
	t_vec2d			dir;
	t_vec2d			map;
	t_vec2d			step;
	t_vec2d			sidedist;
	t_vec2d			deltadist;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	uint32_t		**pixel_data;
	mlx_texture_t	*texture;
}	t_ray;

typedef struct s_rend
{
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_rend;

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
*/
typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					max_width;
	int					g_height;
	int					fd;
	int					map_fd;
	t_list				*lst_map;
	char				**map;
	t_texture			*textures;
	t_player			*player;
	int					ceiling[4];
	int					floor[4];
	t_ray				ray;
	t_keys				keys;
}	t_game;

void			hooks(mlx_key_data_t keydata, void *param);
void			ft_cub_error(char *err, t_game *game);

/* Init */

int				init_game(t_game *game);
void			init_map(int argc, char *argv[], t_game *game);
int				parser(t_game *game);
void			init_player(t_player *player);
void			init_sprites(t_game *game);
void			ft_init_ray(t_ray *ray);

/* Textures */
char			*path_to_sprite(char *sprite_name, int nb);
void			ft_texture_addback(t_texture **lst, t_texture *new);
void			ft_texture_free(t_texture *texture);
void			ft_free_texture_lst(t_texture *lst);

/* Hooks */

void			hook_register(t_game *game);
void			exit_game(t_game *game);
void			press_hooks(mlx_key_data_t keydata, void *param);
void			release_hooks(mlx_key_data_t keydata, void *param);
void			exit_game(t_game *game);

/* Parsing */

int				open_map(char *relative_path, t_game *game);
int				fill_lst(t_game *game);
int				is_enclosed(t_game *game);
int				allowed_char(t_game *game);
int				required_char(t_game *game);

/* Player */
int				movement(t_game *game, t_player *player, int sign, char cross);
void			rotation(t_player *player, int dir);
void			ft_player_init_pos(t_game *game, char dir, int x, int y);
// void			collision(t_game *game, t_player *player);

/* Render */
int				ft_render(t_game *game);
// uint32_t		**ft_init_pixels(void);
int				ft_raycast(t_game *game, t_ray *ray, uint32_t **pixel_data);
void			ft_register_pixels(t_ray *ray, t_game *game,
					uint32_t **pixel_data, int x);
uint32_t		ft_get_color(mlx_texture_t *texture, int pos_x, int pos_y);
unsigned int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

/* Utils */
int				max_width(int width);
void			resize_map(t_game *game);
int				ft_2darr_len(void **arr);
void			ft_2darrfree(void **arr);
float			to_rad(float degree);
double			lerp(double initial, double final, double step);
char			*get_next_line(int fd);

uint64_t		timestamp(void);

#endif