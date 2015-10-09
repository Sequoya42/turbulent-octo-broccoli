/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:01:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 00:45:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char const *g_img_tab[7] = 
{
	"./bitmap/aw.xpm",
	"./bitmap/buddha.xpm",
	"./bitmap/dio.xpm",
	"./bitmap/krgd.xpm",
	"./bitmap/laotseu.xpm",
	"./bitmap/nietz.xpm",
	"./bitmap/scpn.xpm",
};

static char const *g_name_tab[7] = 
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
		e->tab[i] = (char*)g_img_tab[i % 7];
		e->name[i] =(char*)g_name_tab[i % 7];
		e->state[i] = ft_strdup("START");
		e->hp[i] = MAX_LIFE;
		e->i_state[i] = 0;
		if (pthread_mutex_init(&e->lock[i], NULL) != 0)
			ft_exit("Failed to init mutex\n");
		i++;
	}
}

t_env				*init_env(void)
{
	t_env			*e;

	if (PHILO > 17)
		ft_exit("Cannot support more than 17 philosophers\n");
	if (REST_T >= 10 || EAT_T >= 10 || THINK_T >= 10)
		ft_exit("Sleep time is too high\n");
	e = malloc(sizeof(t_env) * 1);
	e->width = 1700;
	if (PHILO > 7)
		e->height = (PHILO > 14 ? 1500 : 1000);
	else
		e->height = 700;
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->win = mlx_new_window(e->mlx,WIDTH, HEIGHT, "Philosopher");
	e->d = mlx_get_data_addr(e->img, &e->bpp, &e->line_size,
&e->endian);
	get_name(e);
	e->id = 0;
	e->roll = 1;
	return (e);
}

