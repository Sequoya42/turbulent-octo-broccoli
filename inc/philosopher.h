/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:03:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/09 00:55:36 by rbaum            ###   ########.fr       */
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

# define REST	"At rest"
# define EAT	"Eating !"
# define THINK	"Thinking about.."

# define MBLUE	0X6CA6CD
# define MRED	0XCD3333
# define MYEL	0XFFB90F
# define MGRN	0X287070
# define MPURP	0X9f4b69

# define WIDTH 	(e->width)
# define HEIGHT	(e->height)

# define MK_ESC	53
# define MK_P	35
# define MK_R	15

# define NEXT(x)	((x + 1) % 7)
# define PREV(x) 	((x == 0) ? 6 : (x - 1) % 7)
# define PHILO		7

# define MAX_LIFE	5
# define EAT_T		1
# define REST_T		1
# define THINK_T	1
# define TIMEOUT	60

# define TT				(10000)
# define TS				(100)
# define FI				(i % 2 ? i : NEXT(i))
# define NI				(i % 2 ? NEXT(i) : i)

# define LOCK(x)		pthread_mutex_lock(x)
# define UNLOCK(x)		pthread_mutex_unlock(x)
# define TRY(x)			pthread_mutex_trylock(x)

# define TX(d)			(100 + ((d % 7) * 220))

typedef struct			s_env
{
	pthread_t			th[PHILO];
	int					hp[PHILO];
	int					i_state[PHILO];
	char				*tab[PHILO];
	char				*name[PHILO];
	char				*state[PHILO];
	pthread_mutex_t		lock[PHILO];
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
	int					roll;
	int					height;
	int					width;
}						t_env;


t_env			*init_env(void);
void			get_name(t_env *e);
int				key_hook(int keycode, t_env *e);
void			ft_mlx_loop(t_env *e);

void			ft_put_philo(t_env *e);
void			print_life(t_env *e);
void			*ft_alg(void *p);
void			ft_think(t_env *e, int l, int i);
void			ft_eat(t_env *e, int l, int r, int i);
void			ft_rest(t_env *e, int i, int ti);

void			ft_init_thread(t_env *e);
void			ft_sleep(int n, int t);
void			ft_pause(t_env *e, int i);
int				ft_is_dead(t_env *e);
void			ft_destroy_mutex(t_env *e);

int				ft_choice(int i, int r);
void			ft_try(t_env *e, int l, int r, int i);
void			try_both(t_env *e, int i);


#endif
