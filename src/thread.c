/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:32:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 00:55:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void			ft_init_thread(t_env *e)
{
	e->id = 0;
	while(1)
	{
		if (pthread_create(&e->th[e->id], NULL, ft_alg , e))
			ft_exit("Failed creating thread, please try again\n");
		usleep(1000);
		if (pthread_detach(e->th[e->id]))
			ft_exit("Failed detaching thread");
		if (e->id == PHILO - 1)
			break;
		e->id++;
	}
}

void	ft_pause(t_env *e, int i)
{
		char	*s;
		char	*s2;
		static int		t2 = 0;

		e->roll = 3;
		t2 = t2 == 0 ? time(NULL) - e->tm : t2;
		s2 = ft_strjoin("Time : ", ft_itoa(t2));
		ft_put_philo(e);
		if (i == 1)
			s = ft_strdup("Now, it is time... To DAAAAAAAANCE ! ! !\n");
		else
			s = ft_strdup("Someone died! ");
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2 + 100 ,MRED, s);
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2 + 140 ,MRED, s2);
		e->tm = 0;
		ft_destroy_mutex(e);
}

void		ft_destroy_mutex(t_env *e)
{
	e->id = 0;
	while (e->id < PHILO)
	{
		usleep(500);
		pthread_mutex_destroy(&e->lock[e->id]);
		e->id++;
	}
}


int				ft_is_dead(t_env *e)
{
	int			i;

	i = -1;
	while (++i < PHILO)
	{
		if (e->hp[i] <= 0)
			return (1);
	}
	return (0);
}