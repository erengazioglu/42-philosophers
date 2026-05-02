/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:42:26 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/02 18:11:29 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	switch_state(t_philo *philo, t_state new_state)
{
	if (new_state == EAT)
		philo->timers.die = philo->settings.die;
	philo->state = new_state;
	print_msg(philo, new_state);
	return (new_state);
}

/**
 * @brief	Creates a new philosopher.
 * @param n	Unique philosopher number (1-indexed).
 * @param settings		Timer length for die, eat, and sleep.
 * @param start_time	T=0 timestamp.
 * @param end_flag		Pointer to shared end simulation flag.
 * @return	Pointer to new philosopher struct, or NULL on malloc failure.
 */
t_philo *new_philo(int n, t_cd settings, long start_time, bool *end_flag)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->end_simulation = end_flag;
	philo->nbr = n;
	philo->state = INIT;
	philo->settings = settings;
	philo->timers = settings;
	philo->eat_count = 0;
	philo->start_time = start_time;
	philo->state = THINK;
	return (philo);
}
