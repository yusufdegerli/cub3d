#include "cub3d.h"

void init2(t_cub3d *cub3d)
{
	;
}

int try_escape(int keycode, t_cub3d *cub3d)
{
	if(keycode == ESC)
	{
		mlx_destroy_window(cub3d->mlx, cub3d->window);
		mlx_clear_window(cub3d->mlx, cub3d->window);
		printf("Closed Succesfully!\n");
		exit(0);
	}
	return (0);
}

void init(t_cub3d *cub3d, char *av)
{
	cub3d = malloc(sizeof(t_cub3d));
	cub3d->mlx = NULL;
	cub3d->window = NULL;
	cub3d->map_datas = (char **) malloc(6 * sizeof(char *));
	cub3d->map = NULL;
	cub3d->tmp_map = NULL;
	cub3d->data_len = 0;
	cub3d->mlx = mlx_init();
	cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_key_hook(cub3d->window, try_escape, cub3d);
	map_ctl(av, cub3d);
	mlx_loop(cub3d->mlx);
}
