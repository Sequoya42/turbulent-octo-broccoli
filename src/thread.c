/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/30 21:40:05 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void			print_life(t_env *e)
{
	TRY(&e->lc);
	int i =-1;
	while (++i < PHILO)
	{
		ft_putnbrn(i);
		ft_putnbrendl(e->hp[i]);
	}
	UNLOCK(&e->lc);
}
void			ft_init_thread(t_env *e)
{
	e->id = 0;
	while (e->id < PHILO)
	{
		if (pthread_create(&e->th[e->id], NULL,ft_alg , e))
			ft_exit("Unknown Failure\n");
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