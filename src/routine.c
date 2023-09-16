/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:12:28 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/16 14:56:54 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_thinking(t_philo *philo)
{
	if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
		return ;
	if (philo->table->life == ALIVE || philo->table->lunch == NOT_FULL)
	print_msg(philo, THINKING);
	philo->mode = WAITING;
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
		return ;
	}
	if (philo->table->life == ALIVE || philo->table->lunch == NOT_FULL)
		print_msg(philo, TAKING);
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
		return ;
	}
	if (philo->table->life == ALIVE \
	|| philo->table->lunch == NOT_FULL)
		print_msg(philo, TAKING);
	philo->mode = EATING;
}

void	eating(t_philo *philo)
{
	if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
		return ;
	}
	philo->diner++;
	if (philo->table->life == ALIVE || philo->table->lunch == NOT_FULL)
		print_msg(philo, EATING);
	philo->last_diner = timer();
	philo->next_diner = timer() + philo->table->time_to_die;
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
	philo->mode = SLEEPING;
}

void	sleeping(t_philo *philo)
{
	if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
		return ;
	if (philo->table->life == ALIVE || philo->table->lunch == NOT_FULL)
	print_msg(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep);
	philo->mode = THINKING;
}

void	only_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print_msg(philo, TAKING);
	ft_usleep(philo->table->time_to_die);
	print_dead_msg(&philo[0], DEAD);
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
}
