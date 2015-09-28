/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 15:09:32 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			*ft_alg(void *p)
{
	t_prs *a;

	a = (t_prs *)p;
	pthread_mutex_lock(&a->lock);
	ft_putstr("BLABLA\n");
    pthread_mutex_unlock(&a->lock);
	return p;
}

void			ft_init_thread(t_prs *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
	if (pthread_create(&p->th[i++], NULL,ft_alg , p))
			ft_exit("Unknown Failure\n");
}

void			ft_join_thread(t_prs *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
		if (pthread_join(p->th[i++], NULL))
			ft_exit("Unknown Failure\n");
}