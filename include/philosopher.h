/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:52:15 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/09 18:04:33 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_mode
{
	WAITING,
	THINKING,
	EATING,
	SLEEPING,
	TAKING,
	DEAD,
	ALIVE,
}	t_mode;

typedef struct s_philo
{
	int				index;
	int				r_fork;
	int				l_fork;
	long			last_diner;
	long			next_diner;
	t_mode			mode;
	struct s_data	*data_philo;
}	t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				number_of_philosophers;
	int				diner;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_mode			mode;
	int				philo_must_eat;
	t_philo			*philo;
}	t_data;

/************
*	Utils	*
*************/

int		ft_atoi(const char *str);
int		it_is_digit(char *str);

/*************
*   Parsing  *
**************/

int		parsing(int argc, char **argv, t_data *data, t_philo *philo);

/*************
*   Dead     *
**************/

bool	philo_is_dead(t_philo *philo);
void	check_philo_is_dead(t_data *data);

/*************
*   Print    *
**************/

void	print_philo(t_philo *philo);
void	print_forks(t_philo *philo);
void	print_mode(t_mode mode);
void	print_msg(t_philo *philo, t_mode mode);
void	print_dead_msg(t_philo *philo, t_mode mode);

/*************
*   Utils2   *
**************/

long	timer(void);
void	ft_usleep(int time);
bool	philo_is_satisfied(t_philo *philo);

/*************
*   Routine  *
**************/

void	take_forks(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

/*************
*   Free     *
**************/

void	ft_free(void *data);
#endif