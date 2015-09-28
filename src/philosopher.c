/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 15:09:15 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int				main(void)
{
	t_prs		*p;
	t_env		*e;

	p = malloc(sizeof(t_prs) * 1);
	e = init_env();
	if (pthread_mutex_init(&p->lock, NULL) != 0)
		ft_exit("Failed to init mutex\n");
	ft_init_thread(p);
	ft_join_thread(p);
	ft_mlx_loop(e);
	pthread_mutex_destroy(&p->lock);
	return (0);
}