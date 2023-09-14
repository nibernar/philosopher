/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:50:46 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/14 16:24:34 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_error(t_error msg)
{
	if (msg == NBR_ARGUMENTS)
		printf("Need more arguments => [number of philo] [time to die] \
[time to eat] [time to sleep] OPTIONAL [nbr of time each philo must eat]\n");
	if (msg == NBR_PHILOS)
		printf("[Number of philo] must be a positiv int\n");
	if (msg == ERR_MALLOC)
		printf("Allocation failed\n");
	if (msg == ERR_THREAD)
		printf("Failed to create a thread\n");
	if (msg == ERR_MUTEX)
		printf("Failed to create a mutex\n");
	if (msg == TTD_ARG)
		printf("[Time to die] must be a positiv int\n");
	if (msg == TTE_ARG)
		printf("[Time to eat] must be a positiv int\n");
	if (msg == TTS_ARG)
		printf("[Time to sleep] must be a positiv int\n");
	if (msg == MUST_EAT_ARG)
		printf("[Number of philo] must be a positiv int\n");
	return (EXIT_FAILURE);
}

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
	pthread_mutex_lock(&philo->data_philo->print);
	printf("%ld %d ", timer(), philo->index);
	print_mode(mode);
	pthread_mutex_unlock(&philo->data_philo->print);
}

void	print_msg(t_philo *philo, t_mode mode)
{
	pthread_mutex_lock(&philo->data_philo->print);
	if (philo->data_philo->life == NOT_ALIVE \
	|| philo->data_philo->lunch == FULL)
	{
		ft_usleep(5);
		pthread_mutex_unlock(&philo->data_philo->print);
		return ;
	}
	printf("%ld %d ", timer(), philo->index);
	print_mode(mode);
	pthread_mutex_unlock(&philo->data_philo->print);
}

static void    print_struct(t_data *data)
{
    printf("nbr of philo        : %d\n", data->number_of_philosophers);
    printf("time to die         : %d\n", data->time_to_die);
    printf("time to eat         : %d\n", data->time_to_eat);
    printf("time to sleep       : %d\n", data->time_to_sleep);
    printf("number of philo eat : %d\n", data->philo_must_eat);
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
    printf("diner               : %d\n", philo->diner);
    print_mode(philo->mode);
    print_struct(philo->data_philo);
    printf("-------------------------------\n");
}