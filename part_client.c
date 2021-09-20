/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:00:03 by Tanguy            #+#    #+#             */
/*   Updated: 2021/09/20 10:17:04 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bbb(int pid, char *message, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((message[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid_server;

	if (ac < 3)
	{
		write(STDERR_FILENO, "ERROR : ./client [pid server] [message]\n", 49);
		return (1);
	}
	pid_server = ft_atoi(av[1]);
	if (pid_server < 0)
	{
		write(STDERR_FILENO, "ERROR : pid can't be less than 0\n", 33);
		return (1);
	}
	send_bbb(pid_server, av[2], ft_strlen(av[2]));
	return (0);
}
