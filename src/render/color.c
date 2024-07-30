#include <cub3d.h>
#include "../../include/cub3d.h"

unsigned int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_get_color(mlx_texture_t *texture, int pos_x, int pos_y)
{
	uint32_t	color;
	int 		pos; 

	pos = (pos_y * TEX_WIDTH + pos_x) * 4;
 	color = get_rgba(texture->pixels[pos],
			texture->pixels[pos + 1], 
            texture->pixels[pos + 2],
            texture->pixels[pos + 3]);
/* 	uint8_t r = texture->pixels[(pos_y * TEX_WIDTH + pos_x) * 4];
    uint8_t g = texture->pixels[(pos_y * TEX_WIDTH + pos_x) * 4 + 1];
    uint8_t b = texture->pixels[(pos_y * TEX_WIDTH + pos_x) * 4 + 2];
	uint8_t a = texture->pixels[(pos_y * TEX_WIDTH + pos_x) * 4 + 3]; */

/*     printf("R: %d, G: %d, B: %d, A: %d Color: %u\n", r, g, b, a, color); 
 	printf("%u\n", get_rgba(r,g,b,a)); */
	return (color);
}
