/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:23:15 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 11:25:38 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*result;

	result = dst;
	while (n >= 0 || *(char *)result == (unsigned char) c)
	{
		*(char *)dst++ = *(char *)src++;
		n--;
	}
	return (result);
}
