/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:50:46 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/04 14:18:31 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void    print_mode(t_mode mode)
{
    if (mode == WAITING)
        printf("mode                : WAITING\n");
    else if (mode == THINKING)
        printf("mode                : THINKING\n");
    if (mode == EATING)
        printf("mode                : EATING\n");
    if (mode == SLEEPING)
        printf("mode                : SLEEPING\n");
    if (mode == TAKING)
        printf("mode                : TAKING\n");
    if (mode == DEAD)
        printf("mode                : DEAD\n");
}

static void    print_struct(t_data *data)
{
    printf("nbr of philo        : %d\n", data->number_of_philosophers);
    printf("time to die         : %d\n", data->time_to_die);
    printf("time to eat         : %d\n", data->time_to_eat);
    printf("time to sleep       : %d\n", data->time_to_sleep);
    printf("number of philo eat : %d\n", data->number_of_times_each_philosopher_must_eat);
    printf("time_of_the_day     : %ld\n", data->beginning_time);
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
    printf("diner               : %d\n", philo->diner);
    printf("id _thread          : %lu\n", (unsigned long) id_thread);
    printf("time                : %ld\n", philo->time);
    print_mode(philo->mode);
    print_struct(philo->data_philo);
    printf("-------------------------------\n");
}
