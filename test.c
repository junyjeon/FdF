#include <mlx.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int main(void)
{
	void *mlx;
	t_data img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** image를 만들었다면, 우리는 `mlx_get_data_addr`을 불러올 수 있다.
	** `bits_per_pixel`, `line_length`, `endian`의 주소를 보낸다.
	** 그러고 나서 보내진 주소는 *현재 데이터 주소*를 위해 적절히 set 될 것이다.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
}