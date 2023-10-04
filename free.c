/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:22:21 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/03 18:17:06 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_cub3d_map(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
}

void	err_data_ctl(char *str, t_cub3d *cub3d)
{
	free_map_info(cub3d);
	free(cub3d);
	printf("%s", str);
	// system("leaks cub3D");
	exit (1);
}

void	err_plyr_ctrl(char *str, t_cub3d *cub3d)
{
	printf("%s", str);
	free_map_info(cub3d);
	free_cub3d_map(cub3d);
	free(cub3d);
	// system("leaks cub3D");
	exit (1);
}

void	error_data_ctl(t_cub3d *cub3d)
{
	if (cub3d->fd < 3)
	{
		printf("ERROR: Map cannot open\n");
		free(cub3d);
		exit (1);
	}
}

void	free_int_map(t_cub3d *cub3d)
{
	int	i;

	i = cub3d->line_count;
	while (--i >= 0)
		free(cub3d->int_map[i]);
	free(cub3d->int_map);
	free(cub3d->move);
	free(cub3d->mouse);
	free(cub3d->player);
}
