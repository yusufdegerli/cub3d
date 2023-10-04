#include "cub3d.h"

void	frame_calc(t_cub3d *cub3d)
{
	int	ct;
	t_math *math;

	ct = -1;
	math = &(cub3d->math);
	while(++ct < WIDTH)
	{
			math->camera_x = 2 * ct / (double) WIDTH - 1;// -1 < ... < 1
			math->raydir_x = cub3d->player->dir_x + cub3d->player->plane_x * math->camera_x;// == -1
			math->raydir_y = -cub3d->player->dir_y + -cub3d->player->plane_y * math->camera_x;// == 0
			math->map_x = (int)cub3d->player->x;// == 22
			math->map_y = (int)cub3d->player->y;// == 11
			if(math->raydir_x == 0)// == 1.000000
				math->deltadist_x = 1e30;
			else
				math->deltadist_x = fabs(1 / math->raydir_x);
			if(math->raydir_y == 0) // == 1000000000000000019884624838656.000000
				math->deltadist_y = 1e30;
			else
				math->deltadist_y = fabs(1 / math->raydir_y);
			math->hit = 0;
			//
			if(math->raydir_x < 0)
			{
				math->step_x = -1;//-1
				math->sidedist_x = (cub3d->player->x - math->map_x) * math->deltadist_x;//22.000000
			}
			else
			{
				math->step_x = 1;
				math->sidedist_x = (math->map_x + 1.0 - cub3d->player->x) * math->deltadist_x;
			}
			if (math->raydir_y < 0)
			{
				math->step_y = -1;
				math->sidedist_y = (cub3d->player->y - math->map_y) * math->deltadist_y;
			}
			else
			{
				math->step_y = 1;//1
				math->sidedist_y = (math->map_y + 1.0 - cub3d->player->y) * math->deltadist_y;//500000000000000009942312419328.000000
			}
			while(math->hit == 0) //prototip aşamasında olduğu için döngü sonsuzda. hit ve side için bir değer döndürmüyor.
			{
				if (math->sidedist_x < math->sidedist_y)
				{
					math->sidedist_x += math->deltadist_x;
					math->map_x += math->step_x;
					math->side = 0;
				}
				else
				{
					math->sidedist_y += math->deltadist_y;
					math->map_y += math->step_y;
					math->side = 1;
				}
				if(cub3d->int_map[math->map_y][math->map_x] > 0)
					math->hit = 1;
			}
			if(math->side == 0)
				math->perpwalldist = (math->sidedist_x - math->deltadist_x);//21.000000
			else
				math->perpwalldist = (math->sidedist_y - math->deltadist_y);
			math->lineheight = (int)(HEIGHT / math->perpwalldist);//28
			math->pitch = 100;
			math->drawstart = -math->lineheight / 2 + HEIGHT / 2 + math->pitch;
			if(math->drawstart < 0)
				math->drawstart = 0; // 386
			math->drawend = math->lineheight / 2 + HEIGHT / 2 + math->pitch;
			if(math->drawend >= HEIGHT)
				math->drawend = HEIGHT - 1; // 414
			math->texnum = cub3d->int_map[math->map_y][math->map_x] - 1;
			if(math->side == 0)
				math->wall_x = cub3d->player->y + math->perpwalldist * math->raydir_y;//11
			else
				math->wall_x = cub3d->player->x + math->perpwalldist * math->raydir_x;
			math->wall_x -= floor(math->wall_x);//0
			math->tex_x = (int)math->wall_x * (double)TEXTWIDHT;//0
			if(math->side == 0 && math->raydir_x > 0)//girmedi
				math->tex_x = TEXTWIDHT - math->tex_x - 1;
			if(math->side == 1 && math->raydir_y < 0)//girmedi
				math->tex_x = TEXTWIDHT - math->tex_x - 1;
			math->step = 1.0 * TEXTHEIGHT / math->lineheight;//2.285714
			math->texpos = (math->drawstart - math->pitch - HEIGHT / 2 + math->lineheight / 2) * math->step;//0.000000
			int	ctt;

			ctt = 0;
			for (; ctt < math->drawstart; ctt++)
				put_pxl_to_img(cub3d, ct, ctt, 0x00000060);
			for (;ctt < math->drawend; ctt++)
			{
				int color = 0x00606000;
				if (math->side == 1)
					color /= 2;
				put_pxl_to_img(cub3d, ct,ctt, color);
			}
			for (; ctt < HEIGHT; ctt++)
				put_pxl_to_img(cub3d, ct, ctt, 0x0000FF00);
	}
}
