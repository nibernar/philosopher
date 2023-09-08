/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:12:28 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/08 16:02:37 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_philo->forks[philo->l_fork]);
	if (philo->data_philo->mode == DEAD || philo_is_satisfied(philo) == true)
	{
		pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
		return ;
	}
	if (philo->data_philo->mode != DEAD)
		print_msg(philo, TAKING);
	pthread_mutex_lock(&philo->data_philo->forks[philo->r_fork]);
	if (philo->data_philo->mode == DEAD || philo_is_satisfied(philo) == true)
	{
		pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
		return ;
	}
	if (philo->data_philo->mode != DEAD)
		print_msg(philo, TAKING);
	philo->mode = EATING;
}

void	philo_thinking(t_philo *philo)
{
	if (philo->data_philo->mode == DEAD || philo_is_satisfied(philo) == true)
		return ;
	if (philo->data_philo->mode != DEAD)
		print_msg(philo, THINKING);
	philo->mode = WAITING;
}

void	eating(t_philo *philo)
{
	if (philo->data_philo->mode == DEAD || philo_is_satisfied(philo) == true)
	{
		pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
		return ;
	}
	philo->last_diner = timer();
	if (philo->data_philo->mode != DEAD)
		print_msg(philo, EATING);
	philo->data_philo->diner++;
	ft_usleep(philo->data_philo->time_to_eat);
	philo->next_diner = timer() + philo->data_philo->time_to_die;
	pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data_philo->forks[philo->r_fork]);
	philo->mode = SLEEPING;
}

void	sleeping(t_philo *philo)
{
	if (philo->data_philo->mode == DEAD || philo_is_satisfied(philo) == true)
		return ;
	if (philo->data_philo->mode != DEAD)
		print_msg(philo, SLEEPING);
	ft_usleep(philo->data_philo->time_to_sleep);
	philo->mode = THINKING;
}
