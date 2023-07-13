/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:05 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/10 17:04:11 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define TAM 20

char	*ft_itoa(int n)
{
	char	str[TAM];
	long	val;
	int		i;
	int		sign;

	i = TAM - 1;
	val = (long) n;
	sign = 0;
	if (val < 0)
	{
		val = -val;
		sign = 1;
	}
	str[i--] = '\0';
	while (val > 0)
	{
		str[i--] = (char)(val % 10 + '0');
		val /= 10;
	}
	if (sign)
		str[i--] = '-';
	if (n == 0)
		str[i--] = '0';
	return (ft_strdup(&str[i + 1]));
}
