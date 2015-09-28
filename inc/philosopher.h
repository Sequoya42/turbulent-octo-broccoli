/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:03:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/28 15:22:28 by rbaum            ###   ########.fr       */
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

# define WIDTH 	1600
# define HEIGHT	1000
# define MK_ESC	53

# define PHILO		7

# define MAX_LIFE	10
# define EAT_T		5
# define REST_T		10
# define THINK_T	5
# define TIMEOUT	10000

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img2;
	char		*d;
	int			bpp;
	int			endian;
	int			line_size;
}				t_env;

typedef struct 		s_prs
{
	pthread_t		th[PHILO];
	int				stick[PHILO];
	pthread_mutex_t	lock;

}					t_prs;


t_env				*init_env(void);
int					key_hook(int keycode, t_env *e);
void				ft_mlx_loop(t_env *e);



void			*ft_alg(void *a);
void			ft_init_thread(t_prs *p);
void			ft_join_thread(t_prs *p);

#endif
