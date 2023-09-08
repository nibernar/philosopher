/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:01 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/08 16:01:37 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (philo->data_philo->mode != DEAD)
	{
		if (philo->data_philo->mode == DEAD \
		|| philo_is_satisfied(philo) == true)
			break ;
		if (philo->index % 2 == 0)
			usleep(30);
		if (philo->mode == THINKING)
			philo_thinking(philo);
		if (philo->mode == WAITING)
			take_forks(philo);
		if (philo->mode == EATING)
			eating(philo);
		if (philo->mode == SLEEPING)
			sleeping(philo);
		dprintf(2, "diner = %d\n", philo->data_philo->diner);
	}
	return (NULL);
}

void	start_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&data->thread[i], NULL, \
		&routine, (void *)&data->philo[i]) != 0)
		{
			printf("error exec thread\n");
			return ;
		}
	}
	check_philo_is_dead(data);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (parsing(argc, argv, &data, philo))
			return (0);
	}
	else
		printf("error\n");
	start_game(&data);
	return (0);
}
