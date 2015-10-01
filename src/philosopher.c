/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/01 17:42:23 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int				continue_alg(t_env *e)
{
	int			t;

	if (TRY(&e->lc) != 0)
		LOCK(&e->lc);
	t = time(NULL);
	if ((t - e->tm) == TIMEOUT)
		ft_pause(e);
	if (e->hp[e->id] < 1 && e->id < PHILO)
	{
		ft_putstr("DEAD DEAD DEAD\t");
		ft_putnbrendl(e->id);
		ft_sleep(2);
		UNLOCK(&e->lc);
		ft_pause(e);
		return 0;
	}
	UNLOCK(&e->lc);
	return (1);
}

void			*ft_alg(void *p)
{
	t_env		*e;
	register int			i;

	e = (t_env *)p;
	i = e->id;
	while (continue_alg(e))
	{
		e->id = i;
		// ft_putnbrendl(i);
		// if (LOCK(&e->lock[i]) == 0 && LOCK(&e->lock[NEXT(i)]))
		// 	ft_eat(e, i);
		// else if (TRY(&e->lock[i]) || TRY(&e->lock[NEXT(i)]))
		// 	ft_think(e, i);
		// else
		// {
		// 	ft_putendl("DDQEGQEGQEGQEGQE$GQEG#");
			ft_rest(e, i);
		// }
	}
	ft_put_philo(e);
	return (p);
}

void		ft_think(t_env *e, int i)
{
	// ft_putstr(KMAG);
	// ft_putstr("THINKING \n");
	e->state[i] = ft_strdup(THINK);
	e->hp[i] -= 1;
	ft_sleep(THINK_T);
	UNLOCK(&e->lock[i]);
	ft_rest(e, i);
}


void		ft_eat(t_env *e, int i)
{
	// ft_putstr(KYEL);
	// ft_putstr("EATING\n");
	e->state[i] = ft_strdup(EAT);
	ft_sleep(EAT_T);
	UNLOCK(&e->lock[i]);
	UNLOCK(&e->lock[(i + 1) % 7]);
	ft_rest(e, i);

}

void		ft_rest(t_env *e, int i)
{
	// ft_putstr(KRED);
	e->state[i] = ft_strdup(NOPE);
	e->hp[i] -= 1;
	ft_sleep(REST_T);
}