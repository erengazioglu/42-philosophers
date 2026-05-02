/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:25:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/02 18:07:01 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init(int n, bool *forks, long start_time, bool *end_flag)
{
	t_cd	settings;
	t_philo	*philo;
	
	settings.die = 1000;
	settings.eat = 800;
	settings.sleep = 500;
	philo = new_philo(n, settings, start_time, end_flag);
	forks[0] = true;
	forks[1] = true;
	return (philo);
}

void	philo_loop(t_philo *philo, bool *forks)
{
	while (philo->state == THINK)
	{
		ph_think(philo);
		if (grab_forks(philo, forks))
			switch_state(philo, EAT);
	}
	while (philo->state == EAT)
		ph_eat(philo, forks);
	while (philo->state == SLEEP)
		ph_sleep(philo);
}

int main(int argc, char **argv)
{
	t_philo	*philo;
	int		eat_target;
	bool	end_simulation;
	bool	forks[2];

	if (argc != 2)
	{
		printf("Usage: %s <times to eat>\n", argv[0]);
		return (1);
	}
	printf("eat: %d, sleep: %d, die: %d\n", 800, 500, 1000);
	end_simulation = false;
	philo = init(1, forks, current_time_ms(), &end_simulation);
	if (!philo)
		return (1);
	eat_target = ft_uatoi(argv[1]);
	switch_state(philo, THINK);
	while (philo->eat_count < eat_target && philo->state != EXIT)
	{
		philo_loop(philo, forks);
		if (philo->state == DIE)
		{
			*(philo->end_simulation) = true;
			philo->state = EXIT;
		}
	}
	return (0);
}
