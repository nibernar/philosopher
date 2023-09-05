/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:52:15 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/04 15:42:11 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/time.h>

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

typedef enum    e_mode
{
	WAITING,
	THINKING,
	EATING,
	SLEEPING,
	TAKING,
	DEAD,
}               t_mode;

typedef struct  s_philo
{
	int				index;
	int				diner;
	int				r_fork;
	int				l_fork;
	int				flag_r_fork;
	int				flag_l_fork;
	long			time;
	t_mode			mode;
	struct s_data	*data_philo;
}       t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	long			beginning_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo *philo;
	
}       t_data;

/************
*	Utils	*
*************/

int		ft_atoi(const char *str);
int		it_is_digit(char *str);

/*************
*   Parsing  *
**************/

int		parsing(int argc, char **argv, t_data *data);

void	print_philo(t_philo *philo);
void print_forks(t_philo *philo);

long  timer(void);

void    *routine(void *data);
#endif