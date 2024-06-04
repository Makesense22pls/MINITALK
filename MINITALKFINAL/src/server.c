/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:20:42 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/03 16:57:31 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static t_oe	*g_struc;

int	ft_reset(int sig, t_oe *g_struc, siginfo_t *info)
{
	if (g_struc->str != NULL)
	{
		free(g_struc->str);
		g_struc->str = NULL;
	}
	g_struc->client_pid = info->si_pid;
	g_struc->index_sig_len = 63;
	g_struc->index_sig_char = 7;
	g_struc->str_index = 0;
	g_struc->len_send = 1;
	g_struc->result_len = 0;
	g_struc->result_char = 0;
	g_struc->len_malloc = 0;
	if (sig == SIGUSR1)
		g_struc->len_malloc |= (1 << g_struc->index_sig_len);
	return (g_struc->len_malloc);
}

void	print(t_oe *g_struc)
{
	g_struc->str[g_struc->str_index] = '\0';
	ft_printf("MA STRING = [%s]\n", g_struc->str);
	if (g_struc->str)
	{
		free(g_struc->str);
		g_struc->str = NULL;
	}
	g_struc->index_sig_len = 63;
	g_struc->str_index = 0;
	g_struc->len_send = 1;
}

int	ft_sig_for_char(int sig, t_oe *g_struc, siginfo_t *info)
{
	if (g_struc->len_send == 1 && g_struc->client_pid == info->si_pid)
	{
		if (sig == SIGUSR1)
			g_struc->len_malloc |= (1 << g_struc->index_sig_len);
		return (g_struc->len_malloc);
	}
	else if (g_struc->len_send == 0 && g_struc->client_pid == info->si_pid)
	{
		if (sig == SIGUSR1)
		{
			g_struc->result_len = g_struc->result_char;
			g_struc->result_len |= (1 << g_struc->index_sig_char);
		}
		return (g_struc->result_len);
	}
	else
	{
		g_struc->len_malloc = ft_reset(sig, g_struc, info);
		return (g_struc->len_malloc);
	}
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	if (g_struc->take_client_pid++ == 0)
		g_struc->client_pid = info->si_pid;
	if (g_struc->index_sig_len >= 0)
	{
		g_struc->len_malloc = ft_sig_for_char(sig, g_struc, info);
		if (--g_struc->index_sig_len == -1)
			g_struc->str = ft_mallocwsh(g_struc);
	}
	else
	{
		g_struc->len_send = 0;
		g_struc->result_char = ft_sig_for_char(sig, g_struc, info);
		if (g_struc->index_sig_len == 63)
		{
			ft_norminette(g_struc, context);
			return ;
		}
		if (--g_struc->index_sig_char != -1)
			return ;
		if (g_struc->result_char != '\0')
			g_struc->str[g_struc->str_index++] = g_struc->result_char;
		else
			print(g_struc);
		ft_set_value_for_new_char(g_struc);
	}
}

int	main(void)
{
	struct sigaction	send;

	g_struc = ft_innit();
	ft_printf("MAFOURNI'S MINITALK\n");
	ft_printf("PID OF SERV = %d\n", getpid());
	send.sa_sigaction = signal_handler;
	send.sa_flags = SA_SIGINFO;
	sigemptyset(&send.sa_mask);
	send.sa_flags = 0;
	sigaction(SIGUSR1, &send, NULL);
	sigaction(SIGUSR2, &send, NULL);
	while (1)
	{
		pause();
	}
}
