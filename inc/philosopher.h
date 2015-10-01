/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:03:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/01 17:45:30 by rbaum            ###   ########.fr       */
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
#include <mlx.h>
#include "libft.h"
#include <errno.h>

# define REST "At rest"
# define EAT "Eating !"
# define THINK "Thinking about.."
# define NOPE "NOPE NOPE NOPE"

# define MBLUE	0X6CA6CD
# define MRED	0XCD3333
# define MYEL	0XFFB90F

# define WIDTH 	1700
# define HEIGHT	1000

# define MK_ESC	53

# define NEXT(x)	((x + 1) % 7)
# define PHILO		7

# define MAX_LIFE	10
# define EAT_T		1
# define REST_T		1
# define THINK_T	1
# define TIMEOUT	200

# define LOCK(x)		pthread_mutex_lock(x)
# define UNLOCK(x)		pthread_mutex_unlock(x)
# define TRY(x)			pthread_mutex_trylock(x)

typedef struct			s_phil
{
	pthread_t			th;
	int					hp;
	int					id;
}						t_phil;

typedef struct			s_env
{
	t_phil				ph[PHILO];
	pthread_t			th[PHILO];
	pthread_mutex_t		lc;
	int					hp[PHILO];
	char				*tab[PHILO];
	char				*name[PHILO];
	char				*state[PHILO];
	pthread_mutex_t		lock[PHILO]; // baguette



	void				*mlx;
	void				*win;
	void				*img;
	void				*img2;
	void				*img3;
	char				*d;
	int					bpp;
	int					endian;
	int					line_size;
	int					id;
	int					tm;
}						t_env;


t_env				*init_env(void);
void				get_name(t_env *e);
int					key_hook(int keycode, t_env *e);
void				ft_mlx_loop(t_env *e);

void			ft_put_philo(t_env *e);
void			print_life(t_env *e);
int				continue_alg(t_env *e);
void			*ft_alg(void *p);
void			ft_think(t_env *e, int i);
void			ft_eat(t_env *e, int i);
void			ft_rest(t_env *e, int i);

void			ft_init_thread(t_env *e);
void			ft_join_thread(t_env *e);
void			ft_sleep(int n);
void			ft_pause(t_env *e);

#endif
