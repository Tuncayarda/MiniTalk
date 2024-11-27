/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:16:30 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/27 17:59:19 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "unistd.h"
# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <sys/types.h>
# define POSIX_C_SOURCE 208009L

typedef struct s_bits
{
	char		c;
	int			count;
}				t_bits;

#endif