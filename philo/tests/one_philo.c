/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:25:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 11:53:34 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init(int n, bool *forks, long start_time)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->nbr = n;
	philo->timers.die = 1000;
	philo->timers.eat = 800;
	philo->timers.sleep = 500;
	philo->eat_count = 0;
	philo->start_time = start_time;
	forks[0] = true;
	forks[1] = true;
	return (philo);
}

t_state	philo_loop(t_philo *philo, bool *forks)
{
	while (!(grab_forks(philo, forks)))
	
}

int main(int argc, char **argv)
{
	t_philo	*philo;
	int		eat_target;
	long	start_time;
	bool	forks[2];

	if (argc != 2)
	{
		printf("Usage: %s <times to eat>\n", argv[0]);
		return (1);
	}
	philo = init(1, forks, current_time_ms());
	if (!philo)
		return (1);
	eat_target = ft_uatoi(argv[1]);
	while (philo->eat_count < eat_target)
	{
		ph_grab(philo, forks);
		ph_eat(philo);
		ph_release(philo, forks);
		if (!ph_sleep(philo, start_time))
			return (0);
		ph_sleep(philo, start_time);
		while (!ph_sleep(philo, start_time))
		ph_think(philo, start_time);
	}
	return (0);
}
