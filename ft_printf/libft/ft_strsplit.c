/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:47:25 by ouzamhar          #+#    #+#             */
/*   Updated: 2018/10/20 13:18:13 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cw(char const *s, char c)
{
	int i;
	int j;
	int b;

	i = 0;
	j = 0;
	b = 1;
	while (s[j])
	{
		if (b == 1 && s[j] != c)
		{
			b = 0;
			i++;
		}
		if (s[j] == c)
			b = 1;
		j++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	size_t	j;
	int		t;

	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (cw(s, c) + 1))))
		return (0);
	while (i < cw(s, c) && s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			t = j;
			while (s[j] != c && j < ft_strlen(s))
				j++;
			str[i++] = (ft_strsub(s, t, j - t));
		}
	}
	str[i] = NULL;
	return (str);
}
