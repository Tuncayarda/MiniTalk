/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:54 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/29 13:57:03 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_received;

void	confirm(int signal)
{
	if (signal == SIGUSR1)
	{
		g_received = 1;
		ft_printf("acknowledge\n");
	}
}

int	send_char(int pid, char c)
{
	int		shift;
	int		status;

	status = 0;
	shift = 7;
	while (shift >= 0)
	{
		g_received = 0;
		if ((c >> shift & 1) == 1)
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		if (status == -1)
			break ;
		if (!g_received)
			pause();
		shift--;
	}
	return (status);
}

int	main(int an, char *args[])
{
	int	i;
	int	pid;

	if (an != 3)
		return (ft_printf("%sInvalid arg entry!!!\n", RED_FONT), 0);
	i = 0;
	pid = ft_atoi(args[1]);
	signal(SIGUSR1, confirm);
	while (args[2][i])
	{
		if (send_char(pid, args[2][i]) == -1)
			return (ft_printf("%sSending signal failure!!!\n", RED_FONT), 1);
		i++;
	}
}
