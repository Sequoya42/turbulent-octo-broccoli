/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 16:45:10 by rbaum            ###   ########.fr       */
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
	return (e);
}

int			key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MK_ESC)
		exit(0);
	return (0);
}

void			ft_mlx_loop(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	int w = 0;
	int h = 0;
	e->img2 = mlx_xpm_file_to_image(e->mlx, "./bitmap/aw.xpm",  &h, &w);
	mlx_put_image_to_window(e->mlx, e->win, e->img2, 100, 0);
	e->img2 = mlx_xpm_file_to_image(e->mlx, "./bitmap/nietz.xpm",  &h, &w);
	mlx_put_image_to_window(e->mlx, e->win, e->img2, 500, 0);
		mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);

}
