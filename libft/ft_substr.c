/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:05:31 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/16 22:07:01 by pbeheyt          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;

	if (start >= ft_strlen_p(s))
	{
		dest = malloc(sizeof(char));
		dest[0] = 0;
		return (dest);
	}
	if (ft_strlen_p(s) < len + start)
		len = ft_strlen_p(s) - start;
	dest = malloc((sizeof(char) * (len + 1)));
	if (dest == 0)
		return (0);
	i = -1;
	while (s[++i + start] != 0 && i < len)
		dest[i] = s[i + start];
	dest[i] = 0;
	return (dest);
}
/*
int	main(void)
{
	char	*str;

	str = "ABCDEFGHIJ";
	printf("%s", ft_substr(str, 1, 4));
	return (0);
}*/
