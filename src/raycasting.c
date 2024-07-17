/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:18:30 by darismen          #+#    #+#             */
/*   Updated: 2024/07/15 13:20:50 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_player(t_game *game)
{
	//Setting player;
	double pos_x = 22, pos_y = 12; //x and y start position
	game->player->pos.x;
	game->player->pos.y;
	
	double dir_x = -1, dir_y = 0; //initial direction vector
	game->player->dir.x;
	game->player->dir.y;

	double plane_x = 0, plane_y = 0.66; //the 2d raycaster version of camera plane
	game->player->cam.x;
	game->player->cam.y;
}

void raycast(t_game *game)
{
	double pos_x = 22, pos_y = 12;
	double dir_x = -1, dir_y = 0;
	double plane_x = 0, plane_y = 0.66;
	int x = 0;
	while (x < WIDTH)
	{
		//calculate ray position and direction
		double camera_x = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
		double raydir_x = dir_x + plane_x * camera_x;
	  	double raydir_y= dir_y + plane_y * camera_x;

		double deltadist_x = abs(1 / raydir_x);
		double deltadist_y = abs(1 / raydir_y);

		//which box of the map we're in
		int map_x = (int)pos_x;
		int map_y = (int)pos_y;

		//length of ray from current position to next x or y-side
		double sidedist_x;
		double sidedist_y;

		//length of ray from one x or y-side to next x or y-side
		if (raydir_x == 0)
			deltadist_x = 1e30;
		else
			abs(1 / raydir_x);
		if (raydir_y == 0)
			deltadist_y = 1e30;
		else
			abs(1 / raydir_y);
		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;
		
		int hit = 0; //was there a wall hit?
    	int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (raydir_x < 0)
		{
			step_x = -1;
			sidedist_x = (pos_x - map_x) * deltadist_x;
		}
		else
		{
			step_x = 1;
			sidedist_x = (map_x + 1.0 - pos_x) * deltadist_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			sidedist_y = (pos_y - map_y) * deltadist_y;
		}
		else
		{
			step_y = 1;
			sidedist_y = (map_y + 1.0 - pos_y) * deltadist_y;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sidedist_x < sidedist_y)
			{
				sidedist_x += deltadist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				sidedist_y += deltadist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall 
			//if (game->map[map_x][map_y] == 1)?
			if (game->map[map_x][map_y] > 0)
				hit = 1;
		}
		double perp_wall_dist;
		//Calculate distance projected on camera direction
			//(Euclidean distance would give fisheye effect!)
		if (side == 0)
			perp_wall_dist = sidedist_x - deltadist_x;
		else
			perp_wall_dist = sidedist_y - deltadist_y;
			
	}
}
