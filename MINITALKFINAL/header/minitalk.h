/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:36:56 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/03 16:56:27 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

typedef struct s_oe
{
	pid_t	client_pid;
	pid_t	server_pid;
	int		take_client_pid;
	int		len_send;
	int		index_sig_len;
	int		index_sig_char;
	int		str_index;
	int		len_malloc;
	int		result_len;
	char	result_char;
	char	*str;
}			t_oe;

char		*ft_mallocwsh(t_oe *g_struc);
t_oe		*ft_innit(void);
void		ft_set_value_for_new_char(t_oe *g_struc);
void		signal_handler(int sig, siginfo_t *info, void *context);
int			ft_reset(int sig, t_oe *g_struc, siginfo_t *info);
void		print(t_oe *g_struc);
int			ft_sig_for_char(int sig, t_oe *g_struc, siginfo_t *info);
void		ft_norminette(t_oe *g_struc, void *context);

#endif