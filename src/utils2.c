/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:55:17 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/09 16:18:41 by nibernar         ###   ########.fr       */
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

	timing = timer() + time;
	while (timer() < timing)
		usleep(50);
}

bool	philo_is_satisfied(t_philo *philo)
{
	if (philo->data_philo->diner == philo->data_philo->philo_must_eat)
		return (true);
	return (false);
}

void	ft_free(void *data)
{
	t_data	*tmp;

	tmp = (t_data *) data;
	free(tmp->philo);
	free((void *) tmp->thread);
	free((void *) tmp->forks);
}