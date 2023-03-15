#include <mlx.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// 괄호 == offset
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *win;
	t_data img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello 42 Seoul");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	// mlx_key_hook(data.win, close, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(mlx);
}