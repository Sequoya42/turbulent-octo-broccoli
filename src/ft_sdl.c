/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 22:14:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/25 22:27:03 by rbaum            ###   ########.fr       */
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

void        create_new_renderer(t_sdl *t)
{
    t->p = (Uint32*)malloc(sizeof(Uint32) * (WIDTH * HEIGHT));
    t->screen = SDL_CreateTexture(t->renderer, SDL_PIXELFORMAT_ARGB8888,
								  SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

intft_init(t_sdl *t)
{
	srand(time(NULL));
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
		("Labyrinth", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1,
									 SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	create_new_renderer(t);
	t->phil = SDL_LoadBMP(".bitmap/dali.bmp");
	t->tabl = SDL_LoadBMP(".bitmap/floor.bmp");
	t->stick = SDL_LoadBMP(".bitmap/shroom.bmp");
	return (0);
}

voidrunning(t_sdl *t)
{
	unsigned intti;
	unsigned intdif;

	t->keystate = SDL_GetKeyboardState(NULL);
	while (1)
	{
		SDL_RenderClear(t->renderer);
		ti = SDL_GetTicks();
		while (SDL_PollEvent(&t->event))
            key_events(t);
		SDL_RenderPresent(t->renderer);
		dif = (SDL_GetTicks() - ti);
		if (dif < 20)
			SDL_Delay(20 - dif);
	}
}
