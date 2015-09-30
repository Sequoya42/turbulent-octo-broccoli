/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:30:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/30 16:17:15 by rbaum            ###   ########.fr       */
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

int				main(void)
{
	t_env		*e;

	e = init_env();
	e->tm = time(NULL);
	ft_init_thread(e);
	// ft_join_thread(e);
	ft_mlx_loop(e);
	return (0);
}