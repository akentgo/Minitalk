/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:14:14 by akent-go          #+#    #+#             */
/*   Updated: 2022/08/12 12:48:53 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	action(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)//si no hay PID asignale el pid de server al valor de la estructura
		client_pid = info->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c) //si no recibo nada, envia una señal vacia al pid de cliente y ponlo a 0, termina la ejecucion
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1); //sino, imprime lo que haya en c, c siendo un char que contiene el valor de la señal que hemos recibido de client, osea si de client envio una a c = 0110 0001
		c = 0;
		kill(client_pid, SIGUSR1); //le envio una señal a cliente para decirle que estoy listo para recibir el siguiente caracter
	}
	else
		c <<= 1; //haz un lsl (logical shift left) si te has mirado los tutoriales de los operadores binarios lo entenderas
}
//Server es bastante más facil de entender que client, lo que hace server es simple, te imprime el PID por pantalla lo primero, usando getpid(), (un poco más abajo)
int	main(void)
{
	struct sigaction		s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);//imprimimos pid
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;//estas dos lineas preguntale a jarredon o alguien que lo tenga mas reciente, estas son estructuras de s_sigaction, una libreria que importamos de forma obligatoria que entiende las señales
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
