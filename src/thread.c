/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/01 17:26:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void			ft_init_thread(t_env *e)
{
	e->id = 0;
	while(1)
	{
		// usleep(1000);
		LOCK(&e->lc);
		if (pthread_create(&e->th[e->id], NULL,ft_alg , e))
			ft_exit("Unknown Failure\n");
		pthread_detach(e->th[e->id]);
		UNLOCK(&e->lc);
		if (e->id == PHILO - 1)
			break;
		e->id++;
	}
}

void			ft_join_thread(t_env *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
		if (pthread_join(p->th[i++], NULL))
			ft_exit("Unknown Failure\n");
	ft_putstr("Joined succesfuulyyyy\n");
}