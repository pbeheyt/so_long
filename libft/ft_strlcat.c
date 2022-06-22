/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/16 21:58:13 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	dest_len_init;

	dest_len = ft_strlen(dest);
	dest_len_init = dest_len;
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] != 0 && dest_len < size - 1)
		dest[dest_len++] = src[i++];
	dest[dest_len] = 0;
	return (dest_len_init + src_len);
}
