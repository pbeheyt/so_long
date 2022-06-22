/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/10 18:10:57 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == 0)
		return ((char *)str);
	if (n == 0)
		return (0);
	j = 0;
	while (str[j] != 0 && j < n)
	{
		i = 0;
		while (str[j + i] == to_find[i] && j + i < n)
		{
			if (to_find[i + 1] == 0)
				return ((char *)&str[j]);
		i++;
		}
	j++;
	}
	return (0);
}
/*
int main (void)
{
	char o[] = "aaabcabcd";
	char u[] = "cd";

	printf("%s", ft_strnstr(o, u, 8));
return (0);
}*/