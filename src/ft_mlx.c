/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/01 17:34:32 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void		ft_destroy_mutex(t_env *e)
{
	int i = 0;
	while (i < PHILO)
	{
			pthread_mutex_destroy(&e->lock[i]);
			i++;
	}
}

void		ft_quit(t_env *e)
{
	ft_destroy_mutex(e);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	ft_pause(t_env *e)
{
		char	*s;

		s = ft_strdup("Now, it is time... To DAAAAAAAANCE ! ! !\n");
		ft_destroy_mutex(e);
		ft_putstr(s);
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT - 100 ,MRED, s);
		ft_sleep(1);
		e->tm = 0;
}

int		loop_hook(t_env *e)
{
	// int		t;

	// t = time(NULL);
	// if ((t - e->tm) == TIMEOUT)
	// 	ft_pause(e);
	ft_putstr("GLGLGLG\n");
	return (e->tm);

}

int			key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MK_ESC)
		ft_quit(e);
	ft_put_philo(e);
	return (0);
}

void			ft_put_philo(t_env *e)
{
	int			d;
	int			x;
	int			y;
	int			wh;

	x = 100;
	y = 300;
	d = 0;
	wh = 0;
	LOCK(&e->lc);
	mlx_clear_window(e->mlx, e->win);
	while (d < PHILO)
	{
		mlx_string_put(e->mlx, e->win, x + 10, y - 50, MYEL, e->state[d]);
		e->img2 = mlx_xpm_file_to_image(e->mlx, e->tab[d],  &wh, &wh);
		mlx_put_image_to_window(e->mlx, e->win, e->img2, x, y);
		mlx_string_put(e->mlx, e->win, x + 10, y + 210, MBLUE, e->name[d]);
		mlx_string_put(e->mlx, e->win, x + 10, y + 260, MRED, ft_itoa(e->hp[d]));
		mlx_string_put(e->mlx, e->win, x + 10, y + 280, MBLUE, ft_itoa(d));
		d++;
		x+= 220;
	}
	UNLOCK(&e->lc);
}

void			ft_mlx_loop(t_env *e)
{
		ft_put_philo(e);
		mlx_key_hook(e->win, key_hook, e);
		// mlx_loop_hook(e->mlx, loop_hook, e);
		mlx_loop(e->mlx);
}
