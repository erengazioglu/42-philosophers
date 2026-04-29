/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:00:10 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/29 19:12:33 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
	t_philo	*philo1;
	t_philo	*philo2;

	init_philos(&philo1, &philo2);
	return (0);
}

t_philo	*init_philo(int n)
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
	return (philo);
}

void	*philo_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
}
