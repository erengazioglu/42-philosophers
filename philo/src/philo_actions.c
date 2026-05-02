/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/02 18:03:38 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Makes the philosopher eat for 10ms.
 * If the eat timer reaches 0, the philosopher releases the forks
 * and goes to sleep.
 * @param philo The philosopher to eat.
 * @param forks The array of forks.
 * @return The new state of the philosopher.
 */
t_state	ph_eat(t_philo *philo, bool *forks)
{
	if (*(philo->end_simulation))
		return (philo->state = EXIT, EXIT);
	usleep(10000);
	philo->timers.eat -= 10;
	if (philo->timers.eat <= 0)
	{
		philo->timers.eat = philo->settings.eat;
		release_forks(philo, forks);
		philo->eat_count++;
		return (switch_state(philo, SLEEP), SLEEP);
	}
	return (EAT);
}

/**
 * @brief Makes the philosopher sleep for 10ms.
 * If the sleep timer reaches 0, the philosopher starts to think.
 * If the die timer reaches 0, the philosopher dies.
 * @param philo The philosopher to sleep.
 * @return The new state of the philosopher.
 */
t_state	ph_sleep(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (switch_state(philo, EXIT), EXIT);
	usleep(10000);
	philo->timers.die -= 10;
	if (philo->timers.die <= 0)
		return (switch_state(philo, DIE), DIE);
	philo->timers.sleep -= 10;
	if (philo->timers.sleep <= 0)
	{
		philo->timers.sleep = philo->settings.sleep;
		return (switch_state(philo, THINK), THINK);
	}
	return (SLEEP);
}

/**
 * @brief Makes the philosopher think for 10ms.
 * If the die timer reaches 0, the philosopher dies.
 * @param philo The philosopher to think.
 * @return The new state of the philosopher.
 */
t_state	ph_think(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (switch_state(philo, EXIT), EXIT);
	philo->timers.die -= 10;
	usleep(10000);
	if (philo->timers.die <= 0)
		return (switch_state(philo, DIE), DIE);
	return (THINK);
}
