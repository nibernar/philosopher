/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:12:28 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/05 20:25:47 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    take_forks(t_philo *philo)
{
    dprintf(2, "index %d flag_l %d  flag_r %d\n", philo->index, philo->flag_l_fork, philo->flag_r_fork);
    if (pthread_mutex_lock(&philo->data_philo->forks[philo->l_fork]) == 0)
    {
        printf("philo [%d] a pris la fourchette gauche %d\n", philo->index, philo->l_fork);
        //philo->flag_l_fork = 1;
        if (pthread_mutex_lock(&philo->data_philo->forks[philo->r_fork]) == 0)
        {
            printf("philo [%d] a pris la fourchette droite %d\n", philo->index, philo->r_fork);
            //philo->flag_r_fork = 1;
             philo->mode = EATING;
        }
    }
    //if (philo->flag_l_fork == 1 && philo->flag_r_fork == 1)
        //philo->mode = EATING;
    dprintf(2, "index %d mode %d\n", philo->index, philo->mode);
}

void    philo_thinking(t_philo *philo)
{
    printf("philo [%d] pense\n", philo->index);
    philo->mode = WAITING;
}

void    eating(t_philo *philo)
{
    printf("philo [%d] mange\n", philo->index);
    philo->flag_l_fork = 0;
    philo->flag_r_fork = 0;
    pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]);
    pthread_mutex_unlock(&philo->data_philo->forks[philo->r_fork]);
    //printf("philo [%d] index forks [%d] retour %d\n", philo->index, philo->l_fork, pthread_mutex_unlock(&philo->data_philo->forks[philo->l_fork]));
    //printf("philo [%d] index forks [%d] retour %d\n", philo->index, philo->r_fork, pthread_mutex_unlock(&philo->data_philo->forks[philo->r_fork]));
    philo->mode = THINKING;
    usleep(2000);
}

// thinking, wainting, eating, sleeping
void    *routine(void *data)
{
    t_philo *philo;

    philo = (t_philo*)data;
    philo->time = timer();
    //print_philo(philo);
    while (1)
    {
        if (philo->mode == THINKING)
        {
            philo_thinking(philo);
            // if (philo->index % 2 == 0)
            //     usleep(50);
        }
        if (philo->mode == WAITING)
            take_forks(philo);
        if (philo->mode == EATING)
            eating(philo);
    }
    return (NULL);
}