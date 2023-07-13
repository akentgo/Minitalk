/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:15:25 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 18:08:26 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			j;
	int			i;
	char		*sol;

	j = 0;
	i = 0;
	if (!s1)
		return (NULL);
	sol = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!sol)
		return (NULL);
	while (s1[i])
	{
		sol[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sol[i] = s2[j];
		i++;
		j++;
	}
	sol[i] = '\0';
	return (sol);
}
