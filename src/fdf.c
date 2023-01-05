/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 16:02:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf"
#include <stdio.h>
#include <cmath.h>

//// Exit the program as failure.
//static void ft_error(void)
//{
//	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
//	exit(EXIT_FAILURE);
//}

//// Print the window width and height.
//static void ft_hook(void* param)
//{
//	const mlx_t* mlx = param;

//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}

//void	key_hook(mlx_key_datae_t key, void *param)
//{
//	if (key.key == MLX_KEY_J && key.action == MLX_PRESS)
//		puts("Hello ");
//	if (key.key == MLX_KEY_K && key.action == MLX_RELEASE)
//		puts("World ");
//	if (key.key == MLX_KEY_L && key.action == MLX_REPEAT)
//		puts("!");
//}

//void	scroll_hook(int x, int y, void *param)
//{
//	if (y > 0)
//		write(1, "Up!",3);
//	else if (y < 0)
//		write(1, "Down!",3);
//	if (x < 0)
//		write(1, "Slide to the left!");
//	else if (x > 0)
//		write(1, "Slide to the left!");
//}

int main(void)
{
	mlx_set_setting(MLX_MAXMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);//픽셀 수정
	mlx_loop_hook(mlx, ft_hook, mlx);//if
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


//int	main(int ac, char **ar)
//{
//	int	fd;
//	int	i;
//	int	j;
//	int	*line;
//	char	*res;
//	char	*init;
//	void	*mlxs;
//	void	*win;
//	mlx_image_t *image;
	
//	mlx_set_setting(MLX_MAXIMIZED, true);
//	mlx_t *mlx = mlx_init(WHDTH, HEIGHT, "42Balls", true);
//	if (!mlx)
//		ft_error();
//	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
//	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
//	j = 1;
//	if (!(fd = open("42.fdf", O_RDONLY)))
//	{
//		perror("Error in file open");
//		return (0);
//	}
//	while (i = get_next_line(fd, &line) > 0)
//	{
//		ft_strjoin(res, line);
//		free(line);
//		j++;
//	}
//	mlx_loop_hook(mlx, ft_hook, mlx);
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 1000, 1000, "테스트");
//	image = mlx_new_image(mlx, 500, 500);
//	if (!새창)
//		return (0);//새 창 열기
//	mlx_loop();//닫기 전까지 열어두기
//	mlx_terminate();//이미지와 리소스를 삭제하고 정리?
	
//	ft_print("%s\n", line);
//	free(line);
//	close(fd);
//	return (0);
//}
//1. is_valid_file_type()
//2. init()
//3. parsing()
//4. vector()
//5. ????
//6. mlx_win()
//7. align?
//8. out
//9. main hook
//10. keyboard hook

//int	main(int ac, char **ar)
//{
//	void	*mlx;
//	void	*win;
//	void	*image;
//	char	*ptr;
	
//	mlx = mlx_init();
//	if (!mlx)
//		return (0);
//	win = mlx_new_window(mlx, 500, 500, "테스트");
//	if (!win)
//		return (0);
//	mlx_loop(mlx);
//	mlx_key_hook(win, 함수, param);
//	mlx_mouse_hook(win, 함수, param);
//	mlx_loop_hook(win, 함수, param);
//	image = mlx_new_image(mlx, 200, 200);
//	if (!image)
//		return (0);
//	int bits_per_pixel = 0;//pixel_color를 표현하기 위해 필요한 bit num (픽셀 하나의 rgb or hue)
//	int size_line = 0;//이미지의 한 줄의 바이트 수
//	int endian = 0;//pixel_color little(0)/big(1) endian little endion 낮은 주소에 낮은 바이트. [12] [34]| big endion [43] [21] 
//	ptr = mlx_get_data_addr (image, &bits_per_pixel, &size_line, &endian);
//	//ptr -> 이미지가 저장된 메모리의 시작주소.
//	mlx_destroy_image();//이미지 제거
//	mlx_get_color_value(mlx, 255); // standard RGB 리턴
//	mlx_pixel_put(mlx, win, x, y, color);//좌표에 픽셀 찍기
//	mlx_string_put(mlx, win, x, y, color);//좌표에 str표시
	
	
//	int create_argb(int a, int r, int g, int b)
//	{
//		return (a << 24 | r << 16 | g << 8 | b);
//	}
//	return (0);
//}
