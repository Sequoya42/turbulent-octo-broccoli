/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/05 20:45:08 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void			ft_quit(t_env *e)
{
	ft_pause(e, 1);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int				loop_hook(t_env *e)
{
	int	t;

	t = time(NULL);
	if (t - e->tm == TIMEOUT)
		e->roll = 3;
	if (e->roll != 3)
		ft_put_philo(e);
	else if (ft_is_dead(e) == 0)
		ft_pause(e, 1);
	else
		ft_pause(e, 2);
	return (e->tm);
}

int				key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MK_ESC)
		ft_quit(e);
	return (0);
}

void			ft_put_philo(t_env *e)
{
	int			d;
	int			y;
	int			wh;

	y = 50;
	d = 0;
	wh = 0;
	mlx_clear_window(e->mlx, e->win);
	while (d < PHILO)
	{
		e->img2 = mlx_xpm_file_to_image(e->mlx, e->tab[d], &wh, &wh);
		if (d != 0 && !(d % 7))
			y += 350;
		if (!ft_strcmp(e->state[d], EAT))
			mlx_string_put(MLX_WIN, TX(d) + 10, y, MPURP, e->state[d]);
		else if (!ft_strcmp(e->state[d], THINK))
			mlx_string_put(MLX_WIN, TX(d) + 10, y, MGRN, e->state[d]);
		else
			mlx_string_put(MLX_WIN, TX(d) + 10, y, MYEL, e->state[d]);
		mlx_put_image_to_window(MLX_WIN, e->img2, TX(d), y + 50);
		mlx_string_put(MLX_WIN, TX(d) + 10, y + 260, MBLUE, e->name[d]);
		mlx_string_put(MLX_WIN, TX(d) + 10, y + 310, MRED, ft_itoa(e->hp[d]));
		d++;
	}
}

void			ft_mlx_loop(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}
