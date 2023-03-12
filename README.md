<picture>
 <source media="(prefers-color-scheme: dark)" srcset="YOUR-DARKMODE-IMAGE">
 <source media="(prefers-color-scheme: light)" srcset="YOUR-LIGHTMODE-IMAGE">
 <img alt="YOUR-ALT-TEXT" src="YOUR-DEFAULT-IMAGE">
</picture>
# fdf
<mlx.h> 헤더를 넣고

mlx_init()으로 그래픽 시스템에 대한 연결을 설정
mlx_new_window()으로 창을 만들고 너비, 높이, 제목을 전달
mlx_new_image()으로 이미지를 만들고 너비, 높이를 전달
mlx_get_data_addr()으로 이미지의 주소를 검색하고 포인터를 bits_per_pixel, line_length 및 endian 변수에 전달
mlx_loop()으로 창 렌더링
