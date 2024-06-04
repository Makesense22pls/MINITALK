/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:26 by maxencefour       #+#    #+#             */
/*   Updated: 2024/06/03 17:01:13 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	send_len(int pidserv, size_t len)
{
	int	i;

	i = 63;
	while (i >= 0)
	{
		if ((1 << i) & len)
			kill(pidserv, SIGUSR1);
		else
			kill(pidserv, SIGUSR2);
		usleep(150);
		i--;
	}
}

void	send_signal(int pidserv, char *message, int len)
{
	int	letter;
	int	i;

	letter = 0;
	send_len(pidserv, len);
	while (message[letter])
	{
		i = 7;
		while (i >= 0)
		{
			if ((1 << i) & (unsigned char)message[letter])
				kill(pidserv, SIGUSR1);
			else
				kill(pidserv, SIGUSR2);
			usleep(75);
			i--;
		}
		letter++;
	}
	i = 7;
	while (i-- >= 0)
	{
		kill(pidserv, SIGUSR2);
		usleep(75);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		len;
	int		pidserv;

	if (argc == 3)
	{
		pidserv = ft_atoi(argv[1]);
		if (!pidserv || pidserv <= -1)
			return (ft_printf("ERROR PID\n"), 0);
		message = argv[2];
		len = ft_strlen(argv[2]);
		if (message[0] == 0)
			return (ft_printf("ERROR WRITE A MESSAGE TO SEND PLS\n"), 0);
		send_signal(pidserv, message, len);
	}
	else
		return (ft_printf("WRONG ARGUMENTS\n"), 0);
	return (0);
}
