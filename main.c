/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:17:09 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/03 14:54:01 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extension_ctl(char *extension)
{
	char	*tmp;
	int		len;

	if (ft_strrchr(extension, '/'))
		tmp = ft_strdup(ft_strrchr(extension, '/'));
	else
		exit (printf("ERROR! Wrong map path!\n"));
	len = ft_strlen(tmp);
	if (len > 4)
	{
		if (tmp[len - 1] != 'b' || tmp[len - 2] != 'u'
			|| tmp[len - 3] != 'c' || tmp[len - 4] != '.')
		{
			perror("Error! The map extension must be .cub!\n");
			free(tmp);
			exit (1);
		}
		free(tmp);
	}
	else
	{
		perror("Error! The map extension must be .cub!2\n");
		free(tmp);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;

	if (!av)
		return (0);
	if (ac != 2)
	{
		perror("Error! Wrong using arguments\n");
		return (1);
	}
	extension_ctl(av[1]);
	init(cub3d, av[1]);
	return (0);
}
