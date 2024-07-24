#include <cube3d.h>

typedef struct mlx_texture
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	uint8_t		*pixels;
}				mlx_texture_t;

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint8_t	ft_get_color(mlx_texture_t *texture, int pos_x, int pos_y)
{
	int		color;
	uint8_t	*pixels;

	pixels = texture->pixels;
	color = get_rgba(texture->pixels[pos_y * WIDTH + pos_x],
			texture->pixels[pos_y * WIDTH + pos_x + 1], 
            texture->pixels[pos_y * WIDTH + pos_x + 2],
            texture->pixels[pos_y * WIDTH + pos_x + 3]);
	return (color);
}
