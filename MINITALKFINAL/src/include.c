/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:43:30 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/03 16:30:47 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_set_value_for_new_char(t_oe *g_struc)
{
	g_struc->result_char = 0;
	g_struc->result_len = 0;
	g_struc->index_sig_char = 7;
}

t_oe	*ft_innit(void)
{
	t_oe	*init;

	init = malloc(sizeof(t_oe));
	if (!init)
		return (NULL);
	init->take_client_pid = 0;
	init->len_send = 1;
	init->len_malloc = 0;
	init->index_sig_len = 63;
	init->index_sig_char = 7;
	init->str_index = 0;
	init->result_len = 0;
	init->result_char = 0;
	init->str = NULL;
	return (init);
}

void	ft_norminette(t_oe *g_struc, void *context)
{
	(void)*context;
	g_struc->len_malloc = g_struc->result_char;
	g_struc->index_sig_len--;
}

char	*ft_mallocwsh(t_oe *g_struc)
{
	g_struc->str = malloc(g_struc->len_malloc + 1);
	if (!g_struc->str)
		return (NULL);
	return (g_struc->str);
}
