/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:01:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 19:55:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void				get_name(t_env *e)
{
	int				i;

	i = -1;
	while (++i < PHILO)
	{
		e->state[i] = REST;
		e->hp[i] = MAX_LIFE;
		// if (pthread_mutex_init(&e->lock[i], NULL) != 0)
			// ft_exit("Failed to init mutex\n");
	}
	e->tab[0] = ft_strdup("./bitmap/aw.xpm");
	e->tab[1] = ft_strdup("./bitmap/buddha.xpm");
	e->tab[2] = ft_strdup("./bitmap/dio.xpm");
	e->tab[3] = ft_strdup("./bitmap/krgd.xpm");
	e->tab[4] = ft_strdup("./bitmap/laotseu.xpm");
	e->tab[5] = ft_strdup("./bitmap/nietz.xpm");
	e->tab[6] = ft_strdup("./bitmap/scpn.xpm");
	e->name[0] =ft_strdup( "Alan Watts");
	e->name[1] =ft_strdup( "Buddha");
	e->name[2] =ft_strdup( "Diogenes");
	e->name[3] =ft_strdup( "Kierkegaard");
	e->name[4] =ft_strdup( "Lao-Tseu");
	e->name[5] =ft_strdup( "Nietsche");
	e->name[6] =ft_strdup( "Schopenhauer");
}

t_env				*init_env(void)
{
	t_env			*e;

	e = malloc(sizeof(t_env) * 1);
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx,WIDTH, HEIGHT);
	e->win = mlx_new_window(e->mlx,WIDTH, HEIGHT, "Philosopher");
	e->d = mlx_get_data_addr(e->img, &e->bpp, &e->line_size,
&e->endian);
	get_name(e);
	e->id = 0;
	return (e);
}

