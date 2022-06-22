/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:05:31 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/10 23:53:38 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	ft_maj(unsigned int test, char c)
{
	(void)test;
	if (c == 32)
		return (c);
	c = c - 32;
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*rs;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	rs = malloc((sizeof(char) * (len + 1)));
	if (rs == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		rs[i] = f(i, s[i]);
	i++;
	}
	rs[i] = 0;
	return (rs);
}
/*
int main(void)
{
	char *test;
	test = ft_strmapi("bonjour comment ca va\n", &ft_maj);
	printf ("%s", test);
	
}*/
