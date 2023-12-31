/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:01 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/22 11:02:08 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (philo->table->number_of_philosophers == 1)
		return (only_one_philo(philo), NULL);
	while (philo->table->life != NOT_ALIVE)
	{
		if (philo->table->life == NOT_ALIVE || philo->table->lunch == FULL)
			break ;
		if (philo->mode == WAITING_ROOM)
		{
			if (philo->index % 2 == 0)
				ft_usleep(5);
			philo->mode = THINKING;
		}
		if (philo->mode == THINKING)
			philo_thinking(philo);
		if (philo->mode == WAITING)
			take_forks(philo);
		if (philo->mode == EATING)
			eating(philo);
		if (philo->mode == SLEEPING)
			sleeping(philo);
	}
	return (NULL);
}

static int	start_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&data->thread[i], NULL, \
		&routine, (void *)&data->philo[i]) != 0)
			return (EXIT_FAILURE, print_error(ERR_THREAD));
	}
	if (data->number_of_philosophers != 1)
		check_philo_situation(data);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		if (parsing(argc, argv, &data, philo))
			return (free_data(&data), 0);
	}
	else
		return (print_error(NBR_ARGUMENTS));
	if (start_game(&data))
		return (free_data(&data), 0);
	free_data(&data);
	return (0);
}
