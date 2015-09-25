/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/25 23:02:09 by rbaum            ###   ########.fr       */
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
int			ft_init(t_sdl *t)
{
	SDL_Rect	pos;

	pos.x = 200;
	pos.y = 200;
	srand(time(NULL));
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
		("Philo", 500, 300, WIDTH, HEIGHT, 0);
	// t->renderer = SDL_CreateRenderer(t->window, -1,
	// 								 SDL_RENDERER_ACCELERATED);
	// SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	t->phil = SDL_LoadBMP("./bitmap/ntz.bmp");
	t->surf = SDL_GetWindowSurface(t->window);
	SDL_BlitSurface(t->phil, NULL, t->surf, &pos);
	SDL_UpdateWindowSurface(t->window);
	return (0);
}
	
void		running(t_sdl *t)
{
	unsigned int ti;
	unsigned int dif;

	t->keystate = SDL_GetKeyboardState(NULL);
	while (1)
	{
		// SDL_RenderClear(t->renderer);
		ti = SDL_GetTicks();
		while (SDL_PollEvent(&t->event))
            key_events(t);
    	// SDL_RenderPresent(t->renderer);
		dif = (SDL_GetTicks() - ti);
		if (dif < 20)
			SDL_Delay(20 - dif);
	}
}
