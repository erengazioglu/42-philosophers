/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 09:29:01 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_forks(bool *forks, int n, long start_time)
{
	if (forks[n - 1] && forks[n])
	{
		forks[n - 1] = false;
		forks[n] = false;
		print_msg(n, TAKE_FORKS, start_time);
	}
	return (true);
}

void	release_forks(bool *forks, int n, long start_time)
{
	forks[n - 1] = true;
	forks[n] = true;
}

void	eat(t_philo *philo, long start_time)
{
	print_msg(philo->nbr, EAT, start_time);
	usleep(philo->cooldowns.eat * 1000);
}

bool	sleep(t_philo *philo, long start_time)
{
	print_msg(philo->nbr, SLEEP, start_time);
	if (philo->cooldowns.sleep > philo->cooldowns.die)
	{
		usleep(philo->cooldowns.die * 1000);
		print_msg(philo->nbr, DIE, start_time);
	}
	usleep(philo->cooldowns.sleep * 1000);
}

void	think(t_philo *philo, long start_time)
{
	if (!philo->is_thinking)
	{
		print_msg(philo->nbr, THINK, start_time);
		philo->is_thinking = true;
	}
	philo->cooldowns.die -= 10;
	usleep(10000);
}