/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:39:47 by akent-go          #+#    #+#             */
/*   Updated: 2022/08/12 12:48:29 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	action(int sig)
{
	static int received = 0;

	if (sig == SIGUSR1) //if the signal is correct, receive = 1
		++received;
	else //else error handler
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	send_signals(int pid, char *str)
{
	int		i;
	char	c;

	while (*str) //while there is a string to be sent
	{
		i = 8;// 8 bits in a byte
		c = *str++;
		while (i--) //send bit by bit
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);//send user signal 2 to said pid
			else
				kill(pid, SIGUSR1);//send user signal 1 to said pid
			usleep(100); //wait 100ms per bit sent
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))//if arguments are incorrect or the argument length is invalid return 1
		return (1);
	ft_putstr_fd("Sent	:", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signals(ft_atoi(argv[1]), argv[2]);
	while(1)
		pause();
	return (0);
}
