/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:54 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/27 18:14:14 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_received;

void	confirm(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

void	send_char(int pid, char c)
{
	int		shift;

	shift = 7;
	while (shift >= 0)
	{
		g_received = 0;
		if ((c >> shift & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!g_received)
			pause();
		shift--;
	}
}

int	main(int an, char *args[])
{
	int	i;
	int	pid;

	if (an != 3)
		return (0);
	i = 0;
	pid = ft_atoi(args[1]);
	signal(SIGUSR1, confirm);
	while (args[2][i])
	{
		send_char(pid, args[2][i]);
		i++;
	}
}
