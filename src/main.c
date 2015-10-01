/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/01 16:59:07 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			ft_sleep(int n)
{
	int			i;

	i = 0;
	while (i < n)
	{
		usleep(1000000);
		i++;
	}
}

int			verif(t_env *e)
{
	int i = 0;
	while (i < PHILO)
	{
		if (!e->th[i])
			return (-1);
		else
{
	ft_putstr("thread number \t");
	ft_putnbrendl(i);
}
		i++;
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
	return (0);
}