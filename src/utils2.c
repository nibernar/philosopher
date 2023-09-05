/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:55:17 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/04 14:00:20 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long  timer(void)
{
    struct timeval  tv;
    long time;

    gettimeofday(&tv, NULL);
    time = 0;
    time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}