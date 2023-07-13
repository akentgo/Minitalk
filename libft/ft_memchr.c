/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:32:07 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/27 16:44:25 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *holas, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)holas == (unsigned char)c)
			return ((void *)holas);
		holas++;
		n--;
	}
	return (NULL);
}
