/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:52:15 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/15 19:34:43 by nicolasbern      ###   ########.fr       */
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
}	t_mode;

typedef enum e_error
{
	NBR_ARGUMENTS,
	NBR_PHILOS,
	ERR_MALLOC,
	ERR_THREAD,
	ERR_MUTEX,
	TTD_ARG,
	TTE_ARG,
	TTS_ARG,
	MUST_EAT_ARG,
}	t_error;

typedef enum e_lunch
{
	FULL,
	NOT_FULL,
}	t_lunch;

typedef enum e_life
{
	ALIVE,
	NOT_ALIVE,
}	t_life;

typedef struct s_philo
{
	int				index;
	int				r_fork;
	int				l_fork;
	long			last_diner;
	long			next_diner;
	int				diner;
	t_mode			mode;
	struct s_data	*data_philo;
}	t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	status;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	size_t			start;
	t_life			life;
	t_lunch			lunch;
	t_philo			*philo;
}	t_data;

/************
*	Utils	*
************/

int		ft_atoi(const char *str);
int		it_is_digit(char *str);

/*************
*   Parsing  *
*************/

int		parsing(int argc, char **argv, t_data *data, t_philo *philo);

/*************
*   Dead     *
*************/

bool	philo_is_dead(t_philo *philo);
void	check_philo_situation(t_data *data);

/*************
*   Print    *
*************/

void	print_philo(t_philo *philo);
void	print_forks(t_philo *philo);
void	print_mode(t_mode mode);
void	print_msg(t_philo *philo, t_mode mode);
void	print_dead_msg(t_philo *philo, t_mode mode);
int		print_error(t_error msg);

/*************
*   Utils2   *
*************/

long	timer(void);
void	ft_usleep(int time);

/*************
*   Routine  *
*************/

void	take_forks(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	only_one_philo(t_philo *philo);

/*************
*    Free    *
*************/

void	ft_free(void *data);

#endif