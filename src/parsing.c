/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:30 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/14 12:34:26 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	init_args(int argc, char **argv, t_data *data)
{
	if (it_is_digit(argv[1]) && ft_atoi(argv[1]) != 0)
		data->number_of_philosophers = ft_atoi(argv[1]);
	else
		exit (print_error(NBR_PHILOS));
	if (it_is_digit(argv[2]))
		data->time_to_die = ft_atoi(argv[2]);
	else
		exit (print_error(TTD_ARG));
	if (it_is_digit(argv[3]))
		data->time_to_eat = ft_atoi(argv[3]);
	else
		exit (print_error(TTE_ARG));
	if (it_is_digit(argv[4]))
		data->time_to_sleep = ft_atoi(argv[4]);
	else
		exit (print_error(TTS_ARG));
	return (EXIT_SUCCESS);
}

static int	init_data(int argc, char **argv, t_data *data)
{
	if (init_args(argc, argv, data))
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		if (it_is_digit(argv[5]) && ft_atoi(argv[5]) != 0)
			data->philo_must_eat = ft_atoi(argv[5]);
		else
			exit (print_error(MUST_EAT_ARG));
	}
	else
		data->philo_must_eat = -1;
	data->lunch = NOT_FULL;
	data->life = ALIVE;
	return (EXIT_SUCCESS);
}

static void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		philo[i].index = i + 1;
		philo[i].l_fork = i;
		if (i % data->number_of_philosophers == 0)
			philo[i].r_fork = (data->number_of_philosophers - 1);
		else
			philo[i].r_fork = i - 1;
		philo[i].mode = THINKING;
		philo[i].diner = 0;
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
		exit (print_error(ERR_MUTEX));
	if (pthread_mutex_init(&data->status, NULL) != 0)
		exit (print_error(ERR_MUTEX));
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			exit (print_error(ERR_MUTEX));
	}
	return (EXIT_SUCCESS);
}

int	parsing(int argc, char **argv, t_data *data, t_philo *philo)
{
	if (init_data(argc, argv, data))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (philo == 0)
		exit (print_error(ERR_MALLOC));
	init_philo(philo, data);
	data->thread = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (data->thread == 0)
		exit (print_error(ERR_MALLOC));
	data->forks = malloc(sizeof(pthread_mutex_t) \
	* data->number_of_philosophers);
	if (data->forks == 0)
		exit (print_error(ERR_MALLOC));
	if (init_mutex(data))
		exit (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
