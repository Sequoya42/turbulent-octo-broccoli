/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/30 16:17:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int				continue_alg(t_env *e)
{
	int			i;

	i = 0;
	while (i < PHILO)
	{
		LOCK(&e->lock[i]);
		if (e->hp[i] == 0)
		{
			UNLOCK(&e->lock[i]);
			return (0);
		}
		UNLOCK(&e->lock[i]);
		i++;
	}
	return (1);
}

void			spec_case(t_env *e)
{
	e->id = e->id + 1 - 1;
}

void			*ft_alg(void *p)
{
	t_env		*e;

	e = (t_env *)p;
	LOCK(&e->lock[e->id]);
	ft_putstr("Thread number :\t");
	ft_putnbrendl(e->id);
	// if (e->id == 7)
	// {
	// 	spec_case(e);
	// 	return (p);
	// }
	// while (1)
	// {
	// 	// ft_putstr("Inside while 1 with number \t");
	// 	// ft_putnbrendl(i);
	// }
	// while (continue_alg(p))
	// {

	// }
	// UNLOCK(&e->lock[e->id]);
	return (p);
}

void		ft_think(t_env *e)
{
	(void)e;
	ft_sleep(THINK_T);
}


void		ft_eat(t_env *e)
{

	(void)e;
	ft_sleep(EAT_T);

}

void		ft_rest(t_env *e)
{

	(void)e;
	ft_sleep(REST_T);
}