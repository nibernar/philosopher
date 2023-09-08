/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:27:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/08 16:03:00 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_dead(t_philo *philo)
{
	if (philo->last_diner >= philo->next_diner)
		return (true);
	return (false);
}

void	check_philo_is_dead(t_data *data)
{
	int	i;

	i = -1;
	while (1)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			if (philo_is_satisfied(&data->philo[i]) == true)
				return ;
			if (philo_is_dead(&data->philo[i]) == true)
			{
				data->mode = DEAD;
				print_dead_msg(&data->philo[i], DEAD);
				return ;
			}
		}
	}
}
