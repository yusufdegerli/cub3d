/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:59:24 by ydegerli          #+#    #+#             */
/*   Updated: 2023/09/20 18:28:00 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int data_chck(char *file_name)
{
	if(ft_strncmp(file_name, "WE ", 3) == 0 || \
		ft_strncmp(file_name, "SO ", 3) == 0 \
			|| ft_strncmp(file_name, "NO  ", 3) == 0 || \
			ft_strncmp(file_name, "EA ", 3) == 0 \
			|| ft_strncmp(file_name, "C ", 2) == 0 || \
			ft_strncmp(file_name, "F ", 2) == 0)
				return (1);
	return (0);
}

// void	map_chck(char *file_name, t_cub3d *cub3d)
// {
// 	int	i;
// 	int	len;

// 	while (1)
// 	{
// 		len = ft_strlen(file_name);
// 		if(ft_strncmp(file_name, "\n", len) == 0)
// 		{
// 			file_name = get_next_line(i)
// 		}
// 	}
// }

char	*data_ctl(char *file_name, t_cub3d *cub3d, int fd)
{
	int	i;
	int	ct;
	int	len;

	ct = 0;
	i = -1;
	fd = open(file_name, O_RDONLY);
	file_name = get_next_line(fd);
	while (1)
	{
		if (data_chck(file_name) == 1)
		{
			cub3d->map_datas[++i] = file_name;
			ct++;
		}
		else if (ct == 6)
			break ;
		file_name = get_next_line(fd);
	}
	if(ct != 6)
	{
		printf("ERROR! Missing some information in the map file!!!\n");
		return(NULL);
		exit(0);
	}
	printf("fd'nin değeri1 %d\n", fd);
	return (file_name);
}

void	map_ctl(char *file_name, t_cub3d *cub3d)
{
	int	fd;
	int	len;

	len = 0;
	fd = 0;
	file_name = data_ctl(file_name, cub3d, fd);
	printf("fd'nin değeri2 %d\n", fd);
	// map_chck(file_name, cub3d);

	// while(1)
	// {
	// 	if(!file_name)
	// 		break;
	// 	file_name = get_next_line(fd);
	// 	if (data_ctl(file_name, cub3d))
	// 		len++;
	// }
}
