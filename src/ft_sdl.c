/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 17:41:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_env				*init_env(void)
{
	t_env			*e;

	e = malloc(sizeof(t_env) * 1);
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx,WIDTH, HEIGHT);
	e->win = mlx_new_window(e->mlx,WIDTH, HEIGHT, "Fractol");
	e->d = mlx_get_data_addr(e->img, &e->bpp, &e->line_size,
&e->endian);
	e->tab[0] = "./bitmap/aw.xpm";
	e->tab[1] = "./bitmap/buddha.xpm";
	e->tab[2] = "./bitmap/dio.xpm";
	e->tab[3] = "./bitmap/krgd.xpm";
	e->tab[4] = "./bitmap/laotseu.xpm";
	e->tab[5] = "./bitmap/nietz.xpm";
	e->tab[6] = "./bitmap/scpn.xpm";
	e->name[0] = "Alan Watts";
	e->name[1] = "Buddha";
	e->name[2] = "Diogenes";
	e->name[3] = "Kierkegaard";
	e->name[4] = "Lao-Tseu";
	e->name[5] = "Nietsche";
	e->name[6] = "Schopenhauer";

	return (e);
}

int			key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MK_ESC)
		exit(0);
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
	while (d < PHILO)
	{
		e->img2 = mlx_xpm_file_to_image(e->mlx, e->tab[d],  &wh, &wh);
		mlx_put_image_to_window(e->mlx, e->win, e->img2, x, y);
		mlx_string_put(e->mlx, e->win, x + 10, y + 210, 0xFFFFFF, e->name[d]);
		d++;
		x+= 220;
	}
}

void			ft_mlx_loop(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	ft_put_philo(e);

	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
}
