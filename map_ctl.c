#include "cub3d.h"

int	data_ctl(char *file_name, t_cub3d *cub3d)
{
	int	i;
	int	len;
	if(ft_strncmp(file_name, "WE ", 3) == 0 || ft_strncmp(file_name, "SO ", 3) == 0 \
		|| ft_strncmp(file_name, "NO  ", 3) == 0 || ft_strncmp(file_name, "EA ", 3) == 0 \
		|| ft_strncmp(file_name, "C ", 2) == 0 ||ft_strncmp(file_name, "F ", 2) == 0)
		{
			printf("Başlıklar doğru\n");
			return (1);
		}
	else
	{
		printf("ERROR!\n");
		exit(0);
	}
	len = ft_strlen(file_name);
	return (0);
}

void	map_ctl(char *file_name, t_cub3d *cub3d)
{
	int	fd;
	int	i;
	int	j;
	int	len;

	len = 0;
	int x = 0;
	fd = open(file_name, O_RDONLY);
	while(1)
	{
		if(!file_name)
			break;
		file_name = get_next_line(fd);
		if(data_ctl(file_name, cub3d) == 0)
			;
		len++;
		x++;
	}
}
