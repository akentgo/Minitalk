/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:13 by akent-go          #+#    #+#             */
/*   Updated: 2023/05/08 16:57:52 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

//SIGUSR1 = 1 SIGUSR2 = 0
void	kill_signals(int pid, char str)
{
	int		i;
	char	c;

	i = 0;
	c = str;
	while (i++ < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent	:", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	while (argv[2][i] != '\0')
	{
		kill_signals(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	kill_signals(ft_atoi(argv[1]), '\n');
	return (0);
}
