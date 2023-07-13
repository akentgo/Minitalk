/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:13:32 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 16:18:51 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)str;
	while (n-- > 0)
		res[i++] = (unsigned char)c;
	return (res);
}
