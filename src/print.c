/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:50:46 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/09 18:04:27 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_mode(t_mode mode)
{
	if (mode == THINKING)
		printf("is thinking\n");
	if (mode == EATING)
		printf("eating\n");
	if (mode == SLEEPING)
		printf("is sleeping\n");
	if (mode == TAKING)
		printf("has taken a fork\n");
	if (mode == DEAD)
		printf("died\n");
}

void	print_dead_msg(t_philo *philo, t_mode mode)
{
	usleep(3);
	pthread_mutex_lock(&philo->data_philo->print);
	printf("%ld %d ", timer(), philo->index);
	print_mode(mode);
	pthread_mutex_unlock(&philo->data_philo->print);
}

void	print_msg(t_philo *philo, t_mode mode)
{
	if (philo->data_philo->mode != DEAD)
	{
		pthread_mutex_lock(&philo->data_philo->print);
		printf("%ld %d ", timer(), philo->index);
		print_mode(mode);
		pthread_mutex_unlock(&philo->data_philo->print);
	}
}

static void    print_struct(t_data *data)
{
    printf("nbr of philo        : %d\n", data->number_of_philosophers);
    printf("time to die         : %d\n", data->time_to_die);
    printf("time to eat         : %d\n", data->time_to_eat);
    printf("time to sleep       : %d\n", data->time_to_sleep);
    printf("number of philo eat : %d\n", data->philo_must_eat);
    printf("diner               : %d\n", data->diner);
}

void print_forks(t_philo *philo)
{
    printf("r_fork              : %d\n", philo->r_fork);
    printf("l_fork              : %d\n", philo->l_fork);
}

void    print_philo(t_philo *philo)
{
    pthread_t   id_thread;
    id_thread = pthread_self();
    printf("-------------------------------\n");
    printf("index philo         : %d\n", philo->index);
    print_forks(philo);
    printf("id _thread          : %lu\n", (unsigned long) id_thread);
    printf("last_diner          : %ld\n", philo->last_diner);
    printf("next_diner          : %ld\n", philo->next_diner);
    print_mode(philo->mode);
    print_struct(philo->data_philo);
    printf("-------------------------------\n");
}