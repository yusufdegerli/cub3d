/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:29 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/28 12:03:50 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		dsize;

	dsize = 0;
	if (dstsize == 0 && dst == NULL)
		return (0);
	while (dst[dsize] != '\0' && dsize < dstsize)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < dstsize)
	{
			dst[dsize] = src[dsize - i];
			dsize++;
	}
	if (i < dstsize)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
