/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:01 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/09 18:35:10 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
// faire philo avec 1 philo
// faire les retours d'err correctement
static void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	// if (philo->data_philo->number_of_philosophers == 1)
	// faire une fonction ou :
	// - il prend une forks + aff msg de take fork 
	// - wait de time to die + aff msg de died
	// - liberer la fork
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
	int i = -1;
	while (++i < data.number_of_philosophers)
		print_philo(&data.philo[i]);
	start_game(&data);
	ft_free((void *)&data);
	return (0);
}
