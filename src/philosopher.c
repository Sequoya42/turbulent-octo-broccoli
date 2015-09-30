/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/30 21:43:04 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int				continue_alg(t_env *e)
{
	int			t;
	int			r;

	LOCK(&e->lc);
	t = time(NULL);
	r = 1;
	if ((t - e->tm) == TIMEOUT)
		ft_pause(e);
	if (e->hp[e->id] < 1)
	{
		ft_putendl("DEAD DEAD DEAD\n");
		ft_sleep(2);
		r = 0;
	}
	UNLOCK(&e->lc);
	return (r);
}

void			*ft_alg(void *p)
{
	t_env		*e;
	int			i;


	e = (t_env *)p;
	i = e->id;
	// ft_putstr(KGRN);
	while (continue_alg(e))
	{
		print_life(e);
		if (TRY(&e->lock[i]) == 0)
		{
			 if (TRY(&e->lock[(i + 1) % 7]) == 0)
				ft_eat(e, i);
			else
				ft_think(e, i);
		}
		else if (TRY(&e->lock[(i + 1) % 7]) == 0)
		{
			if (TRY (&e->lock[i]) == 0)
				ft_eat(e, i);
			ft_think(e, (i + 1) % 7);
		}
		else
			ft_rest(e, i);
	}

	ft_put_philo(e);
	return (p);
}

void		ft_think(t_env *e, int i)
{
	// ft_putstr(KMAG);
	// ft_putstr("THINKING \n");
	e->state[i] = ft_strdup(THINK);
	// e->hp[i] -= 1;
	ft_sleep(THINK_T);
	UNLOCK(&e->lock[i]);
}


void		ft_eat(t_env *e, int i)
{
	// ft_putstr(KYEL);
	// ft_putstr("EATING\n");
	e->state[i] = ft_strdup(EAT);
	ft_sleep(EAT_T);
	UNLOCK(&e->lock[i]);
	UNLOCK(&e->lock[(i + 1) % 7]);

}

void		ft_rest(t_env *e, int i)
{
	// ft_putstr(KRED);
	e->state[i] = ft_strdup(REST);
	// e->hp[i] -= 1;
	ft_sleep(REST_T);
}