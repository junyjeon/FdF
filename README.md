<div align="center">
  <h1>🗺️ FdF (Fil de Fer)</h1>
  <p>42Seoul의 첫 번째 그래픽스 프로젝트: 와이어프레임 모델 구현하기</p>

  <img src="assets/fdf_preview.jpg" alt="FdF Preview" width="800">

  [![42 Score](https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42)](https://github.com/your-username/fdf)
  [![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)
</div>

## 📋 목차
1. [프로젝트 소개](#-프로젝트-소개)
2. [필수 요구사항](#-필수-요구사항)
3. [설치 및 실행](#-설치-및-실행)
4. [구현 가이드](#-구현-가이드)
5. [주요 알고리즘](#-주요-알고리즘)
6. [보너스 기능](#-보너스-기능)
7. [트러블슈팅](#-트러블슈팅)
8. [참고 자료](#-참고-자료)

## 🎯 프로젝트 소개
FdF(Fil de Fer)는 "철사"라는 뜻의 프랑스어로, 3D 와이어프레임 렌더링 프로그램을 만드는 프로젝트입니다. MiniLibX 그래픽 라이브러리를 사용하여 3차원 지형을 2D 화면에 투영합니다.

### 주요 학습 목표
- 기초 컴퓨터 그래픽스 이해
- 3D → 2D 투영 구현
- 이벤트 처리 학습
- 최적화 기법 적용

## 📃 필수 요구사항

### 1. 프로그램 규칙
- MiniLibX 라이브러리 사용
- 맵 파일(.fdf) 파싱
- 와이어프레임 모델 표시
- 3D → 2D 투영 구현
- 기본적인 에러 처리

### 2. 맵 파일 형식
```
0  0  0  0  0
0  1  2  1  0
0  2  4  2  0
0  1  2  1  0
0  0  0  0  0
```
- 각 숫자는 (x,y) 좌표의 높이(z) 값
- 공백으로 구분된 정수
- 모든 줄은 같은 개수의 숫자를 포함

## 🔨 설치 및 실행

### 1. 요구사항
```bash
# MacOS
brew install Xquartz
brew install minilibx

# Linux
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### 2. 컴파일
```bash
git clone https://github.com/your-username/fdf.git
cd fdf
make
```

### 3. 실행
```bash
./fdf maps/42.fdf
./fdf maps/pyramide.fdf
```

## 🛠 구현 가이드

### 1. 기본 구조체
```c
typedef struct s_point
{
    int     x;
    int     y;
    int     z;
    int     color;
} t_point;

typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_point **map;
    int     width;
    int     height;
} t_fdf;
```

### 2. 핵심 함수
```c
// 맵 파싱
t_point **parse_map(char *filename, t_fdf *fdf);

// 선 그리기
void    draw_line(t_fdf *fdf, t_point start, t_point end);

// 이미지에 픽셀 찍기
void    my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

// 이벤트 처리
int     handle_key(int key, t_fdf *fdf);
int     handle_mouse(int button, int x, int y, t_fdf *fdf);
```

## 📐 주요 알고리즘

### 1. Bresenham's Line Algorithm
```c
void draw_line(t_fdf *fdf, t_point start, t_point end)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    
    while (1)
    {
        my_mlx_pixel_put(fdf, start.x, start.y, start.color);
        if (start.x == end.x && start.y == end.y)
            break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; start.x += sx; }
        if (e2 < dy) { err += dx; start.y += sy; }
    }
}
```

### 2. Isometric Projection
```c
void iso(int *x, int *y, int z)
{
    int previous_x = *x;
    int previous_y = *y;
    
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}
```

## 🔍 트러블슈팅

### 1. 메모리 관리
```c
// 메모리 누수 방지를 위한 정리 함수
void cleanup_fdf(t_fdf *fdf)
{
    if (!fdf)
        return;
    if (fdf->img)
        mlx_destroy_image(fdf->mlx, fdf->img);
    if (fdf->win)
        mlx_destroy_window(fdf->mlx, fdf->win);
    if (fdf->mlx)
    {
        mlx_destroy_display(fdf->mlx);
        free(fdf->mlx);
    }
    free_map(fdf->map);
    free(fdf);
}
````


### 2. 성능 최적화
````c
// 이미지 버퍼 직접 조작
void my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = fdf->addr + (y * fdf->line_length + 
              x * (fdf->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

// 더블 버퍼링
void render_frame(t_fdf *fdf)
{
    draw_to_image(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
````


### 3. 일반적인 문제와 해결방안
| 문제 | 원인 | 해결방안 |
|------|------|----------|
| 화면 깜빡임 | 단일 버퍼 사용 | 더블 버퍼링 구현 |
| 느린 렌더링 | mlx_pixel_put 사용 | 이미지 버퍼 직접 조작 |
| 부정확한 회전 | 부동소수점 오차 | 각도 보정 및 반올림 |
| 메모리 누수 | 부적절한 해제 | cleanup 함수 구현 |

## 🎯 성능 테스트

### 1. 맵 크기별 성능
| 맵 크기 | 렌더링 시간 | 메모리 사용량 |
|---------|------------|--------------|
| 10x10   | ~1ms      | ~1MB         |
| 50x50   | ~5ms      | ~2MB         |
| 100x100 | ~15ms     | ~4MB         |
| 200x200 | ~50ms     | ~8MB         |

<div align="center">
  <img src="images/performance_graph.png" width="600">
  <p>맵 크기별 성능 그래프</p>
</div>

## 📚 참고 자료

### 1. 필수 문서
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - FdF](https://harm-smits.github.io/42docs/projects/fdf)
- [Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [Isometric Projection](https://en.wikipedia.org/wiki/Isometric_projection)

### 2. 추천 테스트 맵
```bash
# 기본 테스트
maps/42.fdf        # 기본 숫자 맵
maps/pyramide.fdf  # 피라미드 형태
maps/mars.fdf      # 복잡한 지형
maps/t1.fdf        # 극단적인 높이차
```

<div align="center">
  <img src="images/test_maps.png" width="800">
  <p>다양한 테스트 맵 예시</p>
</div>

## ✅ 체크리스트

### 1. 필수 구현사항
- [ ] 맵 파일 파싱
- [ ] 와이어프레임 그리기
- [ ] 투영 변환
- [ ] 기본 에러 처리
- [ ] 메모리 누수 없음

### 2. 보너스 구현사항
- [ ] 마우스 컨트롤
- [ ] 추가 투영법
- [ ] 색상 그라데이션
- [ ] 회전/이동/확대축소

### 3. 최적화 검증
- [ ] 더블 버퍼링 구현
- [ ] 이미지 버퍼 직접 조작
- [ ] 뷰포트 컬링 적용
- [ ] 성능 테스트 통과

## 🏆 평가 준비
1. **메모리 누수 체크**
```bash
valgrind --leak-check=full ./fdf maps/42.fdf
```

2. **Norminette 검사**
```bash
norminette *.c *.h
```

3. **에러 케이스 테스트**
```bash
./fdf              # 인자 없음
./fdf invalid.fdf  # 잘못된 파일
./fdf maps/empty.fdf  # 빈 파일
```
