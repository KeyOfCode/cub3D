/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:15:50 by darismen          #+#    #+#             */
/*   Updated: 2024/07/30 17:52:10 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* void leaks()
{
	system("leaks -q so_long");
} */

void	ft_cub_error(int type)
{
	if (type == 1)
		ft_putendl_fd("Error \nIncorrect number of arguments!", 2);
	if (type == 2)
		ft_putendl_fd("Error \nUnable to open the map!", 2);
	if (type == 3)
		ft_putendl_fd("Error \nThe map is not in a valid format!", 2);
	if (type == 4)
		ft_putendl_fd("Error \nA sprite could not be opened !", 2);
	if (type == 5)
		ft_putendl_fd("Error \nFATAL ERROR!", 2);
	exit(EXIT_SUCCESS);
}

int	get_rgba(int r, int g, int b, int a);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = ft_calloc(6, sizeof(char *));
	game->map[0] = ft_calloc(27, sizeof(char));
	game->map[1] = ft_calloc(26, sizeof(char));
	game->map[2] = ft_calloc(26, sizeof(char));
	game->map[3] = ft_calloc(26, sizeof(char));
	game->map[4] = ft_calloc(26, sizeof(char));
	game->map[5] = ft_calloc(26, sizeof(char));
	game->map[0] = "1111111111111111111111111";
	game->map[1] = "10S0110000100000000000001";
	game->map[2] = "1000110000000000111111001";
	game->map[3] = "1000110000000000110001001";
	game->map[4] = "1000000000100000000001001";
	game->map[5] = "1111111111111111111111111";
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos.x = 2;
	game->player->pos.y = 1.5;
	game->player->yaw = 270.0;
	game->textures = ft_calloc(4, sizeof(mlx_texture_t *));
	game->textures[0] = mlx_load_png("./west.png"); //WEST
	game->textures[1] = mlx_load_png("./north.png"); //NORTH
	game->textures[2] = mlx_load_png("./hot-dog.png"); //EAST
	game->textures[3] = mlx_load_png("./hot-dog.png"); //SOUTH
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
 	ft_render(game);
	mlx_loop(game->mlx);
	exit(EXIT_SUCCESS);
}
