#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d *cub3d;
	if(!av)
		return (0);
	if(ac != 2)
	{
		perror("Error! Wrong using arguments\n");
		return (1);
	}
	extension_ctl(av[1]);
	init(cub3d, av[1]);

	return (0);
}
