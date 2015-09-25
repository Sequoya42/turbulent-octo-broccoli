/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/25 22:58:26 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			*ft_alg(void *a)
{
	ft_putstr("Correctly initialised thread\n");
	return a;
}

void			ft_init_thread(t_prs *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
	if (pthread_create(&p->th[i++], NULL,ft_alg , NULL))
			ft_exit("Unknown Failure\n");
}

void			ft_join_thread(t_prs *p)
{
	int			i;

	i = 0;
	while (i < PHILO)
		if (pthread_join(p->th[i++], NULL))
			ft_exit("Unknown Failure\n");
		else
			ft_putstr("Joined\n");
}

int				main(void)
{
	t_prs		*p;
	t_sdl		*t;

	p = malloc(sizeof(t_prs) * 1);
	t = malloc(sizeof(t_sdl) * 1);
	ft_init(t);
	running(t);
	ft_init_thread(p);
	ft_join_thread(p);
	return (0);
}