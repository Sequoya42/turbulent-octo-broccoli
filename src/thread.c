/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 20:56:52 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void			ft_init_thread(t_env *p)
{
	while (e->id < PHILO)
	{
	if (pthread_create(&p->th[e->id], NULL,ft_alg , p))
			ft_exit("Unknown Failure\n");
		e->id++;
	}
	e->id = 0
}

void			ft_join_thread(t_env *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
		if (pthread_join(p->th[i++], NULL))
			ft_exit("Unknown Failure\n");
}