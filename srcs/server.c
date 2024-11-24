/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:27:50 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/24 21:15:43 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

void	handler()
{
	ft_printf("test\n");
}

int main()
{
	signal(SIGUSR1, handler);
	ft_printf("PID:%d\n",getpid());
	while(1)
	{
		sleep(1);
	}
}
