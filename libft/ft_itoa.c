/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:34:40 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/12 00:12:02 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int n)
{
	int		len;
	long	nl;

	len = 1;
	nl = n;
	if (nl < 0)
	{
		nl = -nl;
		len++;
	}
	while (nl >= 10)
	{
		nl /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	long			nl;

	nl = n;
	i = nb_len(nl);
	str = malloc(sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	str[i] = 0;
	i--;
	if (nl < 0)
	{
		str[0] = '-';
		nl = -nl;
	}
	if (nl == 0)
		str[i] = 48;
	while (nl > 0)
	{
		str[i] = (nl % 10) + 48;
		nl = nl / 10;
	i--;
	}
	return (str);
}
/*
int	main(void)
{
	//char str[] = "0";
	//printf("%d\n", nb_len(1526));
	printf("%s\n", ft_itoa(__INT_MAX__));
	return (0);
}*/