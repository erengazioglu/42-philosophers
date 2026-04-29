/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:42:28 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/29 19:11:11 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_args(int argc, char **argv, int *arr)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments.\n");
		printf("<philos> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> [meals_required]\n");
		return (false);
	}
	arr[0] = ft_uatoi(argv[1]);
	arr[1] = ft_uatoi(argv[2]);
	arr[2] = ft_uatoi(argv[3]);
	arr[3] = ft_uatoi(argv[4]);
	if (argc == 6)
		arr[4] = ft_uatoi(argv[5]);
	else
		arr[4] = 0;
	if (arr[0] <= 0 || arr[1] <= 0 || arr[2] <= 0
		|| arr[3] <= 0 || arr[4] < 0)
	{
		printf("Error: All arguments must be non-negative integers.\n");
		return (false);
	}
	return (true);
}

long	current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}
