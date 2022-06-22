/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:05:31 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/13 00:08:11 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_p(const char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;

	if (s1 == 0 && s2 == 0)
		return (0);
	size = ft_strlen_p(s1) + ft_strlen_p(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s1 && *s1 != 0)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2 != 0)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	
	s1 = 0;
	s2 = 0;	
	
	printf("%s", ft_strjoin(s1, s2));

	return (0);
}*/
