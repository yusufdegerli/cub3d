#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "mlxlib/mlx.h"
#include "gnl/get_next_line.h"
#include "gnl/get_next_line_bonus.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#define WIDTH 800
#define HEIGHT 600
#define ESC 53

typedef struct s_cub3d
{
	void	*window;
	void	*mlx;
	char	**map;
	char	**tmp_map;
	char	**map_datas;
	int		data_len;
}			t_cub3d;


void	init(t_cub3d *cub3d, char *av);
int		try_escape(int keycode, t_cub3d *cub3d);
void	init2(t_cub3d *cub3d);
int		data_ctl(char *file_name, t_cub3d *cub3d);
void	extension_ctl(char *extension);
void	map_ctl(char *file_name, t_cub3d *cub3d);
#endif
