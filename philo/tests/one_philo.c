/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:25:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 09:28:43 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init(int n, bool *forks)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->nbr = n;
	philo->cooldowns.die = 1000;
	philo->cooldowns.eat = 800;
	philo->cooldowns.sleep = 500;
	philo->eat_count = 0;
	forks[0] = true;
	forks[1] = true;
	return (philo);
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
	philo = init(1, forks);
	if (!philo)
		return (1);
	start_time = current_time_ms();
	eat_target = ft_uatoi(argv[1]);
	while (philo->eat_count < eat_target)
	{
		take_forks(forks, philo->nbr, start_time);
		print_msg(philo, EAT, start_time);
		usleep(philo->cooldowns.eat * 1000);
		philo->eat_count++;
		release_forks(forks, philo->nbr, start_time);
		print_msg(philo, SLEEP, start_time);
		usleep(philo->cooldowns.sleep * 1000, start_time);
		print_msg(philo, THINK, start_time);
	}
	return (0);
}
