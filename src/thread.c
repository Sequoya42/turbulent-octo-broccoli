/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 19:17:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			*ft_alg(void *p)
{
	t_env *a;

	a = (t_env *)p;
	pthread_mutex_lock(&a->lock[a->id]);
	ft_putstr("BLABLA\n");
    pthread_mutex_unlock(&a->lock[a->id]);
	return p;
}

void			ft_init_thread(t_env *p)
{
	while (p->id < PHILO)
	{
	if (pthread_create(&p->th[p->id], NULL,ft_alg , p))
			ft_exit("Unknown Failure\n");
		p->id++;
	}
	p->id = 0;
}

void			ft_join_thread(t_env *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
		if (pthread_join(p->th[i++], NULL))
			ft_exit("Unknown Failure\n");
}