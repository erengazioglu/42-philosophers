/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 11:50:29 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_result	ph_eat(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (EXIT);
	print_msg(philo, EAT);
	usleep(philo->timers.eat * 1000);
	return (CONTINUE);
}

t_result	ph_sleep(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (EXIT);
	print_msg(philo->nbr, SLEEP);
	usleep(10000);
	philo->timers.die -= 10;
	if (philo->timers.die <= 0)
		return (print_msg(philo->nbr, DIE), DEATH);
	philo->timers.sleep -= 10;
	if (philo->timers.sleep <= 0)
	{
		philo->timers.sleep = 0;
		return (print_msg(philo->nbr, THINK), THINK);
	}
	usleep(philo->timers.sleep * 1000);
	return (CONTINUE);
}

t_result	ph_think(t_philo *philo)
{
	if (*(philo->end_simulation))
		return (EXIT);
	if (!philo->is_thinking)
	{
		print_msg(philo->nbr, THINK);
		philo->is_thinking = true;
	}
	philo->timers.die -= 10;
	usleep(10000);
	if (philo->timers.die <= 0)
		return (print_msg(philo->nbr, DIE), DEATH);
	return (CONTINUE);
}
