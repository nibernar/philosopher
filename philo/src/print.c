/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:50:46 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/18 11:28:43 by nibernar         ###   ########.fr       */
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
		printf("[Number of diner] must be a positiv int\n");
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
	size_t	time;

	pthread_mutex_lock(&philo->table->print);
	time = timer() - philo->table->start;
	printf("%ld %d ", time, philo->index);
	print_mode(mode);
	pthread_mutex_unlock(&philo->table->print);
}

void	print_msg(t_philo *philo, t_mode mode)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->print);
	time = timer() - philo->table->start;
	if (philo->table->life == NOT_ALIVE \
	|| philo->table->lunch == FULL)
	{
		ft_usleep(5);
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	printf("%ld %d ", time, philo->index);
	print_mode(mode);
	pthread_mutex_unlock(&philo->table->print);
}
