/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:29:13 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 11:47:36 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*res;
	char	*str;

	str = (char *)src;
	res = (char *)dst;
	if (src == dst)
		return (dst);
	if (str < (char *)dst)
	{
		while (n--)
			*(res + n) = *(str + n);
		return (dst);
	}
	while (n--)
		*res++ = *str++;
	return (dst);
}
