/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:39:07 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/02 16:51:48 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Tries to grab the left and right forks of the philosopher.
 * If both forks are available, it grabs them and returns true.
 * Otherwise, it returns false.
 * @param philo The philosopher trying to grab the forks.
 * @param forks The array of forks (true = available, false = taken).
 * @return True = successfully grabbed, False = failed to grab.
 */
bool	grab_forks(t_philo *philo, bool *forks)
{
	if (forks[philo->nbr - 1] && forks[philo->nbr])
	{
		forks[philo->nbr - 1] = false;
		forks[philo->nbr] = false;
		return (true);
	}
	return (false);
}

/**
 * @brief Releases the left and right forks of the philosopher.
 * @param philo The philosopher releasing the forks.
 * @param forks The array of forks (true = available, false = taken).
 */
void	release_forks(t_philo *philo, bool *forks)
{
	forks[philo->nbr - 1] = true;
	forks[philo->nbr] = true;
}
