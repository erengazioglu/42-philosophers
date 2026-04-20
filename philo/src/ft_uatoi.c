/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:41:47 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/20 11:54:21 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if a character represents a numeric value.
 * @param c		Character to check.
 */
bool	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

/**
 * @brief	Converts the given string to an integer, enforcing 
 * a properly formatted string representing a non-negative integer.
 * @return	The resulting integer, or -1 if there's an error.
 * @note	Does not allow any leading '+' or '-' signs.
 */
int	ft_uatoi(const char *str)
{
	int	acc;
	int	digit;

	if (!(*str))
		return (-1);
	acc = 0;
	while (ft_isdigit(*str))
	{
		digit = *(str++) - '0';
		if (acc > (2147483647 - digit) / 10)
			return (-1);
		acc = acc * 10 + digit;
	}
	if (*str)
		return (-1);
	return (acc);
}
