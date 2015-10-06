/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/06 13:57:16 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			*ft_alg(void *p)
{
	t_env		*e;
	int			i;
	int 		l;
	int			r;

	e = (t_env *)p;
	i = e->id;
	l = i;
	r = NEXT(i);
	while (e->roll != 3)
	{
		usleep(i * 100000);
		if (TRY(&e->lock[FI]) == 0)
		{
			if (TRY(&e->lock[NI]) == 0)
				ft_eat(e, FI, NI, i);
			else
				ft_think(e, FI, NI, i);
		}
		else if (TRY(&e->lock[NI]) == 0)
				ft_think(e, NI, FI, i);
		else
			ft_rest(e, i, 0);
	}
	return (p);
}

void		ft_think(t_env *e, int l, int r, int i)
{
	int		c;
	int		t;
	int		v;

	c = 0;
	v = 0;
	e->state[i] = ft_strdup(THINK);
	while (c < THINK_T)
	{
		t = time(NULL);
		if (ft_is_dead(e) != 0)
			e->roll = 3;
		e->hp[i] -= 1;
		if (TRY(&e->lock[r]) == 0)
		{
			ft_putstr("LOCK SECOND\t");
			ft_putnbrn(r);
			ft_putnbrendl(i);
			return (ft_eat(e, l, r, i));
		}
		if (!ft_strcmp(e->state[r], THINK) && TRY(&e->lock[r]) == EBUSY)
		{
			UNLOCK(&e->lock[l]);
			v = 1;
		}
		ft_sleep(1, t);
		if (v == 1)
		{
			if (TRY(&e->lock[l]) != 0)
			{
				ft_putstr("HOHO lost \t");
			ft_putnbrn(l);
			ft_putnbrendl(i);

				return ft_rest(e, i, c);
			}

		}
		if (e->roll == 3)
			break;
		c++;
	}
	UNLOCK(&e->lock[l]);
}

void		ft_eat(t_env *e, int l, int r, int i)
{
	int		t;
	int		c;

	c = 0;
	e->state[i] = ft_strdup(EAT);
	e->hp[i] = MAX_LIFE;
	while (c < EAT_T)
	{
		if (e->roll == 3)
			break;
		t = time(NULL);
		ft_sleep(1, t);
		c++;
	}
	UNLOCK(&e->lock[l]);
	UNLOCK(&e->lock[r]);
	if (e->roll != 3)
		ft_rest(e, i, 0);
}

void		ft_rest(t_env *e, int i, int ti)
{
	int		c;
	int		t;

	c = 0;
	e->state[i] = ft_strdup(REST);
	while (c < (REST_T - ti))
	{
		if (e->roll == 3)
			break;
		t = time(NULL);
		if (ft_is_dead(e) != 0)
			e->roll = 3;
		e->hp[i] -= 1;
		ft_sleep(1, t);
		c++;
	}
}

