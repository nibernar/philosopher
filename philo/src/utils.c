/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:37:35 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/21 08:40:32 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == '\n' || c == '\r' || c == '\v' || c == '\t' \
			|| c == '\f' || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] != '\0' && (ft_isspace((const int)str[i])))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && (ft_isdigit((int)str[i])))
		if (ft_isdigit((int)str[i]))
			result = result * 10 + (str[i++] - '0');
	result = result * signe;
	if (result >= INT_MAX)
		return (-1);
	return ((int) result);
}

int	it_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}
