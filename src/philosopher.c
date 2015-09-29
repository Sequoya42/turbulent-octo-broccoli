/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 21:02:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			*ft_alg(void *p)
{
	t_env *e;

	e = (t_env *)p;
	while (e->tm != 0)
	{

	}

	return p;
}

void		ft_think(t_env *e, int i)
{
	ft_sleep(THINK_T);
	return (p);
}


void		ft_eat(t_env *e, int i)
{
	ft_sleep(EAT_T);

	return (p);
}

void		ft_rest(t_env *e, int i)
{

	ft_sleep(REST_T);
	return (p);
}