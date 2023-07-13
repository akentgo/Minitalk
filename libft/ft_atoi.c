/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:44:46 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/10 11:19:53 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (*str && (*str == 32 || *str == 9 || *str == '\0' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f'))
		str++;
	if (*str == '+' || *str == '-')
	{	
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		ret = (ret * 10) + (*str - '0');
		if (ret > INT_MAX)
			return (INT_MIN);
		if (ret == INT_MIN)
			return (INT_MIN);
		str++;
	}
	return ((int)ret * sign);
}
