/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:01:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/05 15:39:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char const *g_img_tab[PHILO] = 
{
	"./bitmap/aw.xpm",
	"./bitmap/buddha.xpm",
	"./bitmap/dio.xpm",
	"./bitmap/krgd.xpm",
	"./bitmap/laotseu.xpm",
	"./bitmap/nietz.xpm",
	"./bitmap/scpn.xpm",
};

static char const *g_name_tab[PHILO] = 
{
	"Alan Watts",
	"Buddha",
	"Diogenes",
	"Kierkegaard",
	"Lao-Tseu",
	"Nietsche",
	"Schopenhauer",
};

void				get_name(t_env *e)
{
	int				i;

	i = 0;
	while (i < PHILO)
	{
		e->tab[i] = (char*)g_img_tab[i];
		e->name[i] = (char*)g_name_tab[i];
		e->state[i] = ft_strdup(REST);
		e->hp[i] = MAX_LIFE;
		if (pthread_mutex_init(&e->lock[i], NULL) != 0)
			ft_exit("Failed to init mutex\n");
		i++;
	}
	e->tab[i] = NULL;
	e->name[i] = NULL;
	e->state[i] = NULL;
	e->hp[i] = MAX_LIFE;
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
	e->roll = 1;
	return (e);
}

