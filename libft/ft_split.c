/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:05:31 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/16 06:41:33 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_del(char c, char s)
{
	if (s == c || s == 0)
		return (1);
	return (0);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (is_del(c, s[i]) == 0 && is_del(c, s[i + 1]) == 1)
			words++;
	i++;
	}
	return (words);
}

static void	free_tab(char **tab)
{	
	int	i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free (tab);
}

static int	fill_tab(char **tab, char *s, char c, int words)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (l < words)
	{
		while (is_del(c, s[i]) == 1)
			i++;
		j = 0;
		while (is_del(c, s[j + i]) == 0)
			j++;
		tab[l] = malloc(sizeof(char) * (j + 1));
		if (tab[l] == 0)
			return (-1);
		k = 0;
		while (k < j)
			tab[l][k++] = s[i++];
		tab[l][k] = 0;
	l++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (s == 0)
		return (0);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (tab == 0)
		return (0);
	tab[words] = 0;
	if (fill_tab(tab, (char *)s, c, words) == -1)
	{
		free_tab(tab);
		return (0);
	}
	return (tab);
}
/*
int	main(void)
{
	char	*str;
	char	charset;
	int		i;
	char	**tab;

	charset = 'f';
	str = "🙂f😉f🙁f🙁f🙁f🙁";
	tab = ft_split(str, charset);
	i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d", count_words(str, charset));
	return (0);
}*/
