/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:27:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/14 16:09:44 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_satisfied(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (data->philo_must_eat != -1 && data->philo[i].diner < data->philo_must_eat)
			return (false);
	}
	return (true);
}

bool	philo_is_dead(t_philo *philo)
{
	long time;

	time = timer();
	if (time >= philo->next_diner)
		return (true);
	return (false);
}

void	check_philo_situation(t_data *data)
{
	int	i;

	i = -1;
	while (1)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->status);
			if (data->philo_must_eat != -1 && philo_is_satisfied(data) == true)
			{
				data->lunch = FULL;
				return ;
			}
			if (philo_is_dead(&data->philo[i]) == true)
			{
				data->life = NOT_ALIVE;
				print_dead_msg(&data->philo[i], DEAD);
				return ;
			}
			pthread_mutex_unlock(&data->status);
		}
		ft_usleep(5);
	}
}
