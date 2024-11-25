/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:50 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/25 18:28:23 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_printf.h"
#include "libft.h"
#include <signal.h>
#include <sys/types.h>
#include "server.h"
#define POSIX_C_SOURCE 208009L


t_bits bits;

void	handle(int  signal,siginfo_t *info,void *context)
{

	(void)context;
	
	bits.c = bits.c << 1;
	if (signal == SIGUSR1)
		bits.c = bits.c | 1;
	else if (signal == SIGUSR2)
		bits.c = bits.c | 0;
	kill(info->si_pid, SIGUSR1);
	bits.count++;
	if (bits.count == 8)
	{
		ft_printf("%c", bits.c);
		bits.count = 0;
		bits.c = 0;
	}
		
}

int main()
{
	struct sigaction a;
	
	a.sa_sigaction = handle;
	a.sa_flags= SA_SIGINFO;
	
	bits.c = 0;
	bits.count = 0;
	sigaction(SIGUSR1,&a,NULL);
	sigaction(SIGUSR2,&a,NULL);
	ft_printf("PID:%d\n",getpid());
	while(1)
	{
		pause();
	}
}
