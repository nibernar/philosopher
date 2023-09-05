/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:30 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/04 16:15:10 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int init_data(int argc, char **argv, t_data *data)
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
    if (argc == 6)
    {
        if (it_is_digit(argv[5]))
            data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
        else
            return (EXIT_FAILURE, printf("error number of philo eat\n"));
    }
    else
        data->number_of_times_each_philosopher_must_eat = -1;
    return (EXIT_SUCCESS);
}

static void    init_philo(t_data *data)
{
    int i;

    i = 0;
    while (++i <= data->number_of_philosophers)
    {
        data->philo[i].index = i;
        data->philo[i].l_fork = i;
        if (((i - 1) % data->number_of_philosophers) == 0)
            data->philo[i].r_fork = data->number_of_philosophers;
        else
            data->philo[i].r_fork = i - 1;
        data->philo[i].diner = 0;
        data->philo[i].flag_l_fork = 0;
        data->philo[i].flag_l_fork = 0;
        data->philo[i].data_philo = data;
        data->philo[i].mode = THINKING;
    }
}

void    init_mutex(t_data *data)
{
    int i;

    i = 0;
    while (i <= data->number_of_philosophers)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            printf("error_init_mutex\n");
            return ;
        }
        i++;
    }
}

int    parsing(int argc, char **argv, t_data *data)
{
    data->beginning_time = timer();
    if (init_data(argc, argv, data))
        return (EXIT_FAILURE);
    init_philo(data);
    data->thread = malloc(sizeof(pthread_t) * data->number_of_philosophers);
    if (data->thread == 0)
    {
        printf("error malloc\n");
        return(EXIT_FAILURE);
    }
    data->forks = malloc(sizeof(pthread_t) * data->number_of_philosophers);
    if (data->forks == 0)
    {
        printf("error malloc\n");
        return(EXIT_FAILURE);
    }
    init_mutex(data);
    return (EXIT_SUCCESS);
}