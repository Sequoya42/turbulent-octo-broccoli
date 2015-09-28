/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:03:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 13:18:58 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

// usleep time exit
//pthread_: create detach join
//pthread_mutex: init destroy trlock lock unlock

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "SDL2/SDL.h"
#include "libft.h"

# define WIDTH 	1600
# define HEIGHT	1000
# define KEY 	t->event.key.keysym.sym

# define PHILO		7

# define MAX_LIFE	10
# define EAT_T		5
# define REST_T		10
# define THINK_T	5
# define TIMEOUT	10000


typedef struct		s_sdl
{
	SDL_Surface		*surf;
	SDL_Window		*window;
	SDL_Event		event;
    const Uint8		*keystate;
   	SDL_Surface		*phil;
	SDL_Surface		*tabl;
	SDL_Surface		*stick;
	SDL_Rect		pt[PHILO];

}					t_sdl;

typedef struct 		s_prs
{
	pthread_t		th[PHILO];
	int				stick[PHILO];
	pthread_mutex_t	lock;

}					t_prs;


void				running(t_sdl *t);
int					ft_init_sdl(t_sdl *t);
void				create_new_renderer(t_sdl *t);
void				key_events(t_sdl *t);


void			*ft_alg(void *a);
void			ft_init_thread(t_prs *p);
void			ft_join_thread(t_prs *p);

#endif
