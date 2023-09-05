/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:37:35 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/29 15:38:38 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/**
 * @brief Checks if the character is a space character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is a space character,
 * 0 if the character is not space.
 */
int	ft_isspace(int c)
{
	return (c == '\n' || c == '\r' || c == '\v' || c == '\t' \
			|| c == '\f' || c == ' ');
}

/**
 * @brief Checks if the character is a digital character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is a digital character,
 * 0 if the character is not digital.
 */
static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Convert ASCII string to integer.
 * 
 * @param str The string to convert.
 * @return The new integer, Result of character string conversion.
 */
int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long long	result;

	i = 0;
	signe = 0;
	result = 0;
	while (str[i] != '\0' && (ft_isspace((const int)str[i])))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = 1;
		i++;
	}
	while (str[i] && (ft_isdigit((int)str[i])))
	{
		if (ft_isdigit((int)str[i]))
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if (signe)
		result = result * -1;
	return ((int) result);
}


int	it_is_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit((int)str[i]))
            return (0);
        i++;
    }
	return (1);
}