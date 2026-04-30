/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:39:07 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 11:45:52 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	grab_forks(t_philo *philo, bool *forks)
{
	if (forks[philo->nbr - 1] && forks[philo->nbr])
	{
		forks[philo->nbr - 1] = false;
		forks[philo->nbr] = false;
		print_msg(philo, TAKE_FORKS);
		return (true);
	}
	return (false);
}

void	release_forks(t_philo *philo, bool *forks)
{
	forks[philo->nbr - 1] = true;
	forks[philo->nbr] = true;
}
