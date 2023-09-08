/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:30 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/08 15:58:15 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	init_args(int argc, char **argv, t_data *data)
{
	if (it_is_digit(argv[1]))
		data->number_of_philosophers = ft_atoi(argv[1]);
	else
		return (EXIT_FAILURE, printf("error nbr of philo\n"));
	if (it_is_digit(argv[2]))
		data->time_to_die = ft_atoi(argv[2]);
	else
		return (EXIT_FAILURE, printf("error time to die\n"));
	if (it_is_digit(argv[3]))
		data->time_to_eat = ft_atoi(argv[3]);
	else
		return (EXIT_FAILURE, printf("error time to eat\n"));
	if (it_is_digit(argv[4]))
		data->time_to_sleep = ft_atoi(argv[4]);
	else
		return (EXIT_FAILURE, printf("error time to sleep\n"));
	return (EXIT_SUCCESS);
}

static int	init_data(int argc, char **argv, t_data *data)
{
	if (init_args(argc, argv, data))
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		if (it_is_digit(argv[5]))
			data->philo_must_eat = ft_atoi(argv[5]);
		else
			return (EXIT_FAILURE, printf("error number of philo eat\n"));
	}
	else
		data->philo_must_eat = -1;
	data->diner = 0;
	data->mode = ALIVE;
	return (EXIT_SUCCESS);
}

static void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		philo[i].index = i;
		philo[i].l_fork = i;
		if (i % data->number_of_philosophers == 0)
			philo[i].r_fork = (data->number_of_philosophers - 1);
		else
			philo[i].r_fork = i - 1;
		philo[i].mode = THINKING;
		philo[i].data_philo = data;
		philo[i].last_diner = timer();
		philo[i].next_diner = timer() + data->time_to_die;
	}
	data->philo = philo;
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		printf("error_init_mutex\n");
		return (EXIT_FAILURE);
	}
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("error_init_mutex\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	parsing(int argc, char **argv, t_data *data, t_philo *philo)
{
	if (init_data(argc, argv, data))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (philo == 0)
	{
		printf("error malloc\n");
		return (EXIT_FAILURE);
	}
	init_philo(philo, data);
	data->thread = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (data->thread == 0)
	{
		printf("error malloc\n");
		return (EXIT_FAILURE);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) \
	* data->number_of_philosophers);
	if (data->forks == 0)
	{
		printf("error malloc\n");
		return (EXIT_FAILURE);
	}
	if (init_mutex(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
