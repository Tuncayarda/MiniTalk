/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:50 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/27 18:16:26 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_bits	g_bits;

void	handle(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_bits.c = g_bits.c << 1;
	if (signal == SIGUSR1)
		g_bits.c = g_bits.c | 1;
	else if (signal == SIGUSR2)
		g_bits.c = g_bits.c | 0;
	g_bits.count++;
	if (g_bits.count == 8)
	{
		ft_printf("%c", g_bits.c);
		g_bits.count = 0;
		g_bits.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	a;

	a.sa_sigaction = handle;
	a.sa_flags = SA_SIGINFO;
	g_bits.c = 0;
	g_bits.count = 0;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	ft_printf("PID:%d\n", getpid());
	while (1)
		pause();
}
