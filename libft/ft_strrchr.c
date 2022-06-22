/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/09 19:20:09 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	j;
	char			*ptr;

	ptr = 0;
	j = 0;
	while (str[j] != 0)
	{
		if ((unsigned char)c == str[j])
			ptr = (char *) &str[j];
	j++;
	}
	if (c == 0)
		return ((char *) &str[j]);
	return (ptr);
}
/*
int main (void)
{
	char o[] = "salut ca va";
	char u = '\0';

	printf("%p\n", ft_strrchr(o, u));
	printf("%p\n", strrchr(o, u));
return (0);
}*/