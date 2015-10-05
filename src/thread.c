/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/05 16:11:36 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void			ft_init_thread(t_env *e)
{
	e->id = 0;
	while(1)
	{
		if (pthread_create(&e->th[e->id], NULL,ft_alg , e))
			ft_exit("Failed creating thread\n");
		usleep(100000);
		if (e->id == PHILO - 1)
			break;
		e->id++;
	}
}

void			ft_join_thread(t_env *e)
{
	int			i;

	i = -1;
	while (++i < PHILO)
		if (pthread_join(e->th[i], NULL))
			ft_exit("Unknown Failure\n");
	ft_putstr("Joined succesfuulyyyy\n");
}

void		ft_detach_thread(t_env *e)
{
	int			i;

	i = -1;
	while (++i < PHILO)
		if (pthread_detach(e->th[i]))
			ft_exit("Unknown Failure\n");

}