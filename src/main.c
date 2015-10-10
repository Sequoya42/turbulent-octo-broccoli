/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 00:56:42 by rbaum            ###   ########.fr       */
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

int				main(int ac, char **av)
{
	t_env		*e;
	int			k;

	k = 0;
	if (ac == 2 && !ft_strcmp(av[1], "immortal"))
		k = 1;
	else if (ac != 1)
		ft_exit("No argument needed\n");
	e = init_env(k);
	e->tm = time(NULL);
	ft_init_thread(e);
	ft_mlx_loop(e);
	return (0);
}
