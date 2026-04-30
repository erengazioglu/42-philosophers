/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 12:04:16 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	ph_eat(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (philo->state = EXIT, EXIT);
	print_msg(philo, EAT);
	usleep(10000);
	philo->timers.eat -= 10;
	if (philo->timers.eat <= 0)
	{
		philo->timers.eat = philo->settings.eat;
		philo->eat_count++;
		return (philo->state = SLEEP, SLEEP);
	}
	return (EAT);
}

t_state	ph_sleep(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (philo->state = EXIT, EXIT);
	usleep(10000);
	philo->timers.die -= 10;
	if (philo->timers.die <= 0)
		return (print_msg(philo, DIE), philo->state = DIE, DIE);
	philo->timers.sleep -= 10;
	if (philo->timers.sleep <= 0)
	{
		philo->timers.sleep = philo->settings.sleep;
		return (print_msg(philo, THINK), philo->state = THINK, THINK);
	}
	return (SLEEP);
}

t_state	ph_think(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (philo->state = EXIT, EXIT);
	philo->timers.die -= 10;
	usleep(10000);
	if (philo->timers.die <= 0)
		return (print_msg(philo, DIE), philo->state = DIE, DIE);
	return (THINK);
}
