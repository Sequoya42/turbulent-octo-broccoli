/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:03:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 20:05:13 by rbaum            ###   ########.fr       */
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

# define REST "At rest"
# define EAT "Eating !"
# define THINK "Thinking about.."

# define MBLUE	0X6CA6CD
# define MRED	0XCD3333
# define MYEL	0XFFB90F

# define WIDTH 	1700
# define HEIGHT	1000

# define MK_ESC	53

# define PHILO		7

# define MAX_LIFE	10
# define EAT_T		5
# define REST_T		10
# define THINK_T	5
# define TIMEOUT	2

typedef struct			s_env
{
	pthread_t			th[PHILO];
	pthread_mutex_t		lock[PHILO];
	char				*tab[PHILO];
	char				*name[PHILO];
	char				*state[PHILO];
	int					hp[PHILO];
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


void			*ft_alg(void *a);
void			ft_init_thread(t_env *e);
void			ft_join_thread(t_env *e);
void			ft_sleep(int n);

#endif
