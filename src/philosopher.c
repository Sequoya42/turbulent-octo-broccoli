/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 14:06:20 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/29 19:16:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void		*ft_think(void *p)
{
	ft_sleep(THINK_T);
	return (p);
}


void		*ft_eat(void *p)
{
	ft_sleep(EAT_T);
	return (p);
}

void		*ft_rest(void *p)
{
	ft_sleep(REST_T);
	return (p);
}