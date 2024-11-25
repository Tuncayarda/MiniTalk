/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:54 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/25 18:39:03 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>
#define POSIX_C_SOURCE 208009L

int	status;

void	confirm(int signal)
{
	if (signal == SIGUSR1)
		status = 0;
}

void	send_char(int pid, char c)
{
	int		shift;

	shift = 7;
	while (shift >= 0)
	{
		status = 1;
		if ((c >> shift & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (status)
			pause();
		usleep(2);
		status = 1;
		shift--;
	}
}

int main(int an, char* args[])
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(args[1]);
	signal(SIGUSR1, confirm);
	while (args[2][i])
	{
		send_char(pid, args[2][i]);
		i++;
	}
	
}
