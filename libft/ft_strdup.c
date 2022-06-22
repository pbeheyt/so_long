/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:05:31 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/03 18:43:45 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i] != 0)
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	dup[i] = 0;
	i--;
	while (i >= 0)
	{
		dup[i] = src[i];
	i--;
	}
	return ((char *) dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char 	*str;

	str = ft_strdup("Hello\n");
	free(str);
	str = NULL;
	if (str == NULL)
		printf("c null");
	printf("%s", ft_strdup(""));
	return (0);
}*/
