/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:55:17 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/12 14:59:48 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	timer(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = 0;
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_usleep(int time)
{
	long	timing;

	if (time == 0)
		timing = timer() + 1;
	else
		timing = timer() + time;
	while (timer() < timing)
		usleep(50);
}

void	ft_free(void *data)
{
	t_data	*tmp;

	tmp = (t_data *) data;
	free(tmp->philo);
	free((void *) tmp->thread);
	free((void *) tmp->forks);
}