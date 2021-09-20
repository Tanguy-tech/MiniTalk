/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:00:01 by Tanguy            #+#    #+#             */
/*   Updated: 2021/08/10 09:08:52 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_content	g_content;

void	get_bbb(int bit)
{
	g_content.c += ((bit & 1) << g_content.size);
	g_content.size++;
	if (g_content.size == 7)
	{
		ft_putchar(g_content.c);
		if (!g_content.c)
			ft_putchar('\n');
		g_content.c = 0;
		g_content.size = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_content.c = 0;
	g_content.size = 0;
	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, get_bbb);
		signal(SIGUSR1, get_bbb);
		pause();
	}
	return (0);
}
