/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:17:57 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 12:40:29 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*start;
	char	*end;
	char	*res;

	start = (char *)s1;
	end = start + ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	while (*start && is_set(*(start), (char *)set))
			++start;
	while (start < end && is_set(*(end - 1), (char *)set))
		--end;
	res = ft_substr(start, 0, end - start);
	return (res);
}
