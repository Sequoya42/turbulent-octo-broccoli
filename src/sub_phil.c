/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_phil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 21:11:43 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 21:11:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int				ft_choice(int i, int r)
{
	int			ch;

	if (i % 2 == 0)
		ch = (r % 2 == 0) ? PREV(i) : NEXT(i);
	else
		ch = (r % 2 == 0) ? NEXT(i) : PREV(i);
	return (ch);
}

void			ft_try(t_env *e, int l, int r, int i)
{
	int			ch;

	ch = ft_choice(i, r);
	if (TRY(&e->lock[r]) == 0)
		ft_eat(e, l, r, i);
	else if (TRY(&e->lock[r]) == EBUSY && !ft_strcmp(e->state[ch], THINK))
	{
		e->i_state[i] = 1;
		usleep(TS + 36);
		if (TRY(&e->lock[r]) == 0)
			ft_eat(e, l, r, i);
	}
	else
		ft_think(e, l, i);
}

void			try_both(t_env *e, int i)
{
	e->i_state[i] = 1;
	usleep(TS + 36);
	if (TRY(&e->lock[FI]) == 0)
	{
		if (TRY(&e->lock[NI]) == 0)
			ft_eat(e, FI, NI, i);
		else
			ft_think(e, FI, i);
	}
	else if (TRY(&e->lock[NI]) == 0)
		ft_think(e, NI, i);
	else
	{
		e->i_state[i] = 0;
		ft_rest(e, i, 0);
	}
}
