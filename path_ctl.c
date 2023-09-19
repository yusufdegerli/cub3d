#include "cub3d.h"

void extension_ctl(char *extension)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup(ft_strrchr(extension, '/'));
	len = ft_strlen(tmp);
	if (len > 4)
	{
		if(tmp[len - 1] != 'b' || tmp[len - 2] != 'u'
			|| tmp[len - 3] != 'c' || tmp[len - 4] != '.')
		{
			perror("Error! The map extension must be .cub!\n");
			free(tmp);
			exit(1);
		}
		free(tmp);
	}
	else
	{
		perror("Error! The map extension must be .cub!2\n");
		free(tmp);
		exit(1);
	}
	
}
