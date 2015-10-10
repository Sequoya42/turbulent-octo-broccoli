/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 00:44:56 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			never_die(t_env *e, int i)
{
	if (e->imortal != 1)
		return ;
	if (e->hp[i] == 1)
	{
		ft_putnbrendl(i);
		LOCK(&e->lock[FI]);
		LOCK(&e->lock[NI]);
		ft_eat(e, FI, NI, i);
	}
}

void			*ft_alg(void *p)
{
	t_env		*e;
	int			i;

	e = (t_env *)p;
	i = e->id;
	while (e->roll != 3)
	{
		never_die(e, i);
		if (!ft_strcmp(e->state[NEXT(i)], THINK) &&
			!ft_strcmp(e->state[PREV(i)], THINK))
			try_both(e, i);
		else if (TRY(&e->lock[FI]) == 0)
			ft_try(e, FI, NI, i);
		else if (TRY(&e->lock[NI]) == 0)
			ft_try(e, NI, FI, i);
		else
			ft_rest(e, i, 0);
	}
	if (pthread_detach(e->th[i]))
		ft_putendl("Error while detaching thread");
	return (p);
}

void			ft_think(t_env *e, int l, int i)
{
	int		c;
	int		rt;

	c = 0;
	rt = THINK_T * TT;
	e->i_state[i] = 0;
	e->state[i] = ft_strdup(THINK);
	while (c < rt)
	{
		if (ft_is_dead(e) != 0)
			e->roll = 3;
		if ((c % TT) == 0)
			e->hp[i] -= 1;
		if (e->i_state[NEXT(i)] == 1 || e->i_state[PREV(i)] == 1)
		{
			UNLOCK(&e->lock[l]);
			return (ft_rest(e, i, c));
		}
		usleep(TS);
		if (e->roll == 3)
			break ;
		c++;
	}
	UNLOCK(&e->lock[l]);
}

void			ft_rest(t_env *e, int i, int ti)
{
	int		c;
	int		rt;

	c = ti;
	rt = (REST_T * TT);
	if (!ft_strcmp(e->state[i], EAT))
		e->state[i] = ft_strdup("REST(PE)");
	else if (!ft_strcmp(e->state[i], THINK))
		e->state[i] = ft_strdup("REST(PT)");
	else
		e->state[i] = ft_strdup(REST);
	while (c < rt)
	{
		if (ft_is_dead(e) != 0)
			e->roll = 3;
		if (c % TT == 0)
			e->hp[i] -= 1;
		if (e->roll == 3)
			break ;
		usleep(TS);
		c++;
	}
}

void			ft_eat(t_env *e, int l, int r, int i)
{
	int		t;
	int		c;

	c = 0;
	e->i_state[i] = 0;
	e->state[i] = ft_strdup(EAT);
	e->hp[i] = MAX_LIFE;
	while (c < EAT_T)
	{
		if (e->roll == 3)
			break ;
		t = time(NULL);
		ft_sleep(1, t);
		c++;
	}
	UNLOCK(&e->lock[l]);
	UNLOCK(&e->lock[r]);
	if (e->roll != 3)
		ft_rest(e, i, 0);
}
