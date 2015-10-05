/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/05 20:43:52 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			ft_sleep(int n, int t)
{
	int			i;
	int			ti;

	i = 0;
	ti = time(NULL) - t;

	while (i < n)
	{
		usleep(1000000);
		i++;
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
int				main(void)
{
	t_env		*e;

	e = init_env();
	e->tm = time(NULL);
	ft_init_thread(e);
	ft_mlx_loop(e);
	// ft_join_thread(e);
	return (0);
}