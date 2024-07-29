#include <cub3d.h>
#include "../../include/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	ft_get_color(mlx_texture_t *texture, int pos_x, int pos_y)
{
	unsigned int	color;

	color = get_rgba(texture->pixels[(pos_y * WIDTH  + pos_x) * 4],
			texture->pixels[(pos_y * WIDTH  + pos_x) * 4 + 1], 
            texture->pixels[(pos_y * WIDTH  + pos_x) * 4 + 2],
            texture->pixels[(pos_y * WIDTH + pos_x) * 4 + 3]);
/* 	uint8_t r = texture->pixels[(pos_y * WIDTH + pos_x) * 4];
    uint8_t g = texture->pixels[(pos_y * WIDTH + pos_x) * 4 + 1];
    uint8_t b = texture->pixels[(pos_y * WIDTH + pos_x) * 4 + 2];
	uint8_t a = texture->pixels[(pos_y * WIDTH + pos_x) * 4 + 3];

    printf("R: %d, G: %d, B: %d, A: %d Color: %d\n", r, g, b, a, color);
	printf("%d\n", get_rgba(r,g,b,a)) */;
	 //65535
	return (color);
}
