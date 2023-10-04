/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:02 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/04 13:57:15 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->dir_x;
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(-cub3d->move->rot_speed) \
		- cub3d->player->dir_y * sin(-cub3d->move->rot_speed);
	cub3d->player->dir_y = old_dir_x * sin(-cub3d->move->rot_speed) + \
		cub3d->player->dir_y * cos(-cub3d->move->rot_speed);
	cub3d->player->plane_x = cub3d->player->plane_x * \
		cos(-cub3d->move->rot_speed) - cub3d->player->plane_y * \
		sin(-cub3d->move->rot_speed);
	cub3d->player->plane_y = old_plane_x * sin(-cub3d->move->rot_speed) + \
		cub3d->player->plane_y * cos(-cub3d->move->rot_speed);
}

void	rotate_with_mouse(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_x;
	//printf("calisti\n");
	rot_x = (double) -cub3d->move->rot_speed * ((cub3d->mouse->pos_x - \
		cub3d->mouse->old_pos_x) / 10.0);
	printf("rot: %f\n", rot_x);
	//exit(1);
	old_dir_x = cub3d->player->dir_x;
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->dir_x = (double) (cub3d->player->dir_x * cos(rot_x) \
		- cub3d->player->dir_y * sin(rot_x));
	cub3d->player->dir_y = (double) (old_dir_x * sin(rot_x) + \
		cub3d->player->dir_y * cos(rot_x));
	cub3d->player->plane_x = (double) cub3d->player->plane_x * cos(rot_x)
		- cub3d->player->plane_y * sin(rot_x);
	cub3d->player->plane_y = (double) old_plane_x * sin(rot_x) + \
		cub3d->player->plane_y * cos(rot_x);
	mlx_mouse_move(cub3d->window, WIDTH / 2, HEIGHT / 2);
	printf("player x : %f  y : %f pause: %d\trot x: %f rot Y: %f plane_x: %f plane_y: %f\n", cub3d->player->x, cub3d->player->y, cub3d->lock , cub3d->player->dir_x, cub3d->player->dir_y, cub3d->player->plane_x, cub3d->player->plane_y);
}

void	move(t_cub3d *cub3d)
{
	if (cub3d->move->forward == 1)
		move_forward(cub3d);
	else if (cub3d->move->backward == 1)
		move_back(cub3d);
	if (cub3d->move->left == 1)
		move_left(cub3d);
	else if (cub3d->move->right == 1)
		move_right(cub3d);
	if (cub3d->move->rot_left == 1)
		rot_left(cub3d);
	else if (cub3d->move->rot_right == 1)
		rot_right(cub3d);
	if (cub3d->move->forward == 1 || cub3d->move->backward == 1 || \
		cub3d->move->left == 1 || cub3d->move->right == 1 || \
		cub3d->move->rot_left == 1 ||cub3d->move->rot_right == 1)
		printf("player x : %f  y : %f pause: %d\trot x: %f rot Y: %f plane_x: %f plane_y: %f\n", cub3d->player->x, cub3d->player->y, cub3d->lock , cub3d->player->dir_x, cub3d->player->dir_y, cub3d->player->plane_x, cub3d->player->plane_y);
}
