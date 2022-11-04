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

//Para el minitalk necesitas conocimientos sobre señales, vas a usar 2 tipos de señal SIGUSR1 y SIGUSR2, estas son señales que enviamos los usuarios manualmente

static void	action(int sig)
{
	//Esta funcion recibe una señal y confirma que es correcta antes de enviarla
	static int received = 0;

	//Este primer if comprueba que la señal que enviamos SIGUSR1 coincide con el argumento del programa en el caso de que no funcione lanzamos el handler de errores
	if (sig == SIGUSR1) //if the signal is correct, receive = 1
		++received;
	else //else error handler
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}
//esta funcion es la encargada de, una vez comprobada la SIGUSR1 la enviemos a server
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
			if (c >> i & 1) //Utilizamos operadores logicos (miratelo en internet, w3schools lo explica guay) para comprobar que lo enviado es correcto
				kill(pid, SIGUSR2);/*kill, es una funcion que no significa matar AJAJA, significa enviar señal, el primer argumento es el PID o process ID que
				este PID lo sacamos cuando ejecutamos server, entonces esta linea, coge el pid de server y le envia la señal SIGUSR2 que es un 1	
			*/
			else
				kill(pid, SIGUSR1);//Esta linea envia a PID SIGUSR1 que es un 0
			usleep(100); //la funcion usleep para la ejecucion del programa una cantidad de milisegundos, más especificamente, lo que hay dentro del parentesis
		}
	}
	i = 8; //recuerda hay 8 bits en un byte
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))//Si los argumentos no son válidos o hay más de 3 argumentos sal del programa
		return (1);
	ft_putstr_fd("Sent	:", 1); //esto es unb printf basicamente y la siguiente linea tb
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	//sube a la funcion action
	signal(SIGUSR1, action);//comprobamos sigusr1
	signal(SIGUSR2, action);//comprobamos sigusr2
	send_signals(ft_atoi(argv[1]), argv[2]); //enviamos señales
	while(1)
		pause();//esperamos a el siguiente comando
	return (0);
}
