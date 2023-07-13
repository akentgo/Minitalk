/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:12:20 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/11 10:35:15 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_tokens(char *str, char c)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str != c)
		{
			res++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (res);
}

char	**divide(const char *s, char c, char **ret, int length)
{
	int	it;

	it = 0;
	while (*s)
	{
		if (*s != c)
		{
			length = 0;
			while (*s && *s != c)
			{
				++length;
				++s;
			}
			ret[it++] = ft_substr(s - length, 0, length);
		}
		else
			++s;
	}
	ret[it] = NULL;
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		length;

	length = 0;
	ret = malloc(sizeof(char *) * n_tokens((char *)s, c) + sizeof(void *));
	if (!ret)
		return (NULL);
	ret = divide(s, c, ret, length);
	return (ret);
}
