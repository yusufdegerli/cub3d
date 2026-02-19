/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:50:39 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 16:22:46 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			new[j++] = s[i];
			i++;
	}
	new[j] = '\0';
	return (new);
}
/*
#include <stdio.h>
int main()
{
	char yusuf[] = "Merhabafghjhejskhjrnslgjwlxdjgmek";
	printf("%s", ft_substr(yusuf, 3, 8));
}*/
