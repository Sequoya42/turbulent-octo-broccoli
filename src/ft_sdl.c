/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 13:24:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void        key_events(t_sdl *t)
{
	if (t->event.type == SDL_KEYDOWN)
    {
        if (KEY == 27)
        {
            SDL_DestroyWindow(t->window);
            SDL_Quit();
            exit(1);
        }
    }
}

void		round_philo(t_sdl *t)
{
	SDL_Rect	pos;

	pos.x = 100;
	pos.y = 100;
	int i = 0;
	while (i < PHILO)
	{
		SDL_BlitSurface(t->phil, NULL, t->surf, &pos);
		if (pos.x < WIDTH - (t->phil->w + t->phil->w))
			pos.x += t->phil->w + t->phil->w;
		else
		{
			pos.x = 300;
			pos.y += t->phil->h + t->phil->h;
		}
		i++;
	}
}

int			ft_init_sdl(t_sdl *t)
{
	srand(time(NULL));
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
		("Philo", 300, 250, WIDTH, HEIGHT, 0);
	t->phil = SDL_LoadBMP("./bitmap/ntz.bmp");
	t->stick = SDL_LoadBMP("./bitmap/b3.bmp");
	t->surf = SDL_GetWindowSurface(t->window);
	SDL_Rect pt;
	pt.x = 520;
	pt.y = 150;
	SDL_BlitSurface(t->stick, NULL, t->surf, &pt);
	round_philo(t);
	return (0);
}
	
void		running(t_sdl *t)
{
	unsigned int ti;
	unsigned int dif;

	t->keystate = SDL_GetKeyboardState(NULL);
	while (1)
	{
		ti = SDL_GetTicks();
		while (SDL_PollEvent(&t->event))
            key_events(t);
		dif = (SDL_GetTicks() - ti);
		if (dif < 20)
			SDL_Delay(20 - dif);
		SDL_UpdateWindowSurface(t->window);
	}
}
