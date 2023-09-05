/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:01 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/04 15:53:11 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    start_game(t_data *data)
{
    int i;

    i = 1;
    while (i <= data->number_of_philosophers)
    {
        if (pthread_create(&data->thread[i], NULL, &routine, (void *)&data->philo[i]) != 0)
        {
            printf("error exec thread\n");
            return ;
        }
        usleep(1000);
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(data->thread[i], NULL);
        i++;
    }
}


int main(int argc, char **argv)
{
    t_data  data;

    if (argc == 5 || argc == 6)
    {
        if (parsing(argc, argv, &data))
            return (0);
    }
    else
        printf("error\n");
    start_game(&data);
    return (0);
}